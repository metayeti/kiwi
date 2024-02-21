////////////////////////////////////////////////////////////////////////////////
///   __    __         __ 
///  |  | _|__|_  _  _|__|   Kit for Interactive World Integration
///  |  |/ /  \ \/ \/ /  |   A 2D game map editor
///  |    <|  |\  _  /|  |   ( version 0.0.2 dev )
///  |__|_ \__| \/ \/ |__|   https://github.com/metayeti/kiwi
///       \/              
///
///  Licensed under GPL3 ( https://www.gnu.org/licenses/gpl-3.0.en.html )
///  Based on the wxWidgets library ( https://www.wxwidgets.org/ )
///
///  Copyright (c) 2024 Danijel Durakovic
///
/// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
///
///  dlg_newlayer.cpp
///  ---
///  New layer dialog implementation.
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_newlayer.h"
#include "../const.h"

void kiwi::DlgNewLayer::EnableDisableComponents()
{
	if (chkMatchMapSize->IsChecked()) {
		spnLayerWidth->Enable(false);
		spnLayerHeight->Enable(false);
		spnOffsetLeft->Enable(false);
		spnOffsetTop->Enable(false);
	}
	else {
		spnLayerWidth->Enable(true);
		spnLayerHeight->Enable(true);
		spnOffsetLeft->Enable(true);
		spnOffsetTop->Enable(true);
	}
}

void kiwi::DlgNewLayer::OnCheckBoxMatchMapSize(wxCommandEvent& e)
{
	EnableDisableComponents();
}

kiwi::DlgNewLayer::DlgNewLayer(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "Create a New Layer", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	const int borderSize = FromDIP(GUI_DEFAULT_BORDER_SIZE);
	const int halfBorderSize = FromDIP(GUI_HALF_BORDER_SIZE);
	const int hGapSize = FromDIP(GUI_DEFAULT_GRID_HORIZONTAL_GAP);

	auto sizRoot = new wxBoxSizer(wxVERTICAL); // root sizer

	auto panDialogElements = new wxPanel(this, wxID_ANY, wxDefaultPosition);
	panDialogElements->SetMinSize(FromDIP(wxSize(400, 210)));
	sizRoot->Add(
		panDialogElements,
		1,
		wxEXPAND | wxALL,
		borderSize
	);
	{
		auto sizDialogElements = new wxBoxSizer(wxVERTICAL);
		panDialogElements->SetSizer(sizDialogElements);
		{
			auto sizFlexGrid = new wxFlexGridSizer(2, 2, borderSize, hGapSize);
			sizFlexGrid->AddGrowableCol(1, 1);
			sizDialogElements->Add(
				sizFlexGrid,
				0,
				wxEXPAND
			);
			{
				auto lblLayerName = new wxStaticText(panDialogElements, wxID_ANY, "Layer name:");
				sizFlexGrid->Add(
					lblLayerName,
					0,
					wxALIGN_CENTER_VERTICAL
				);

				auto txtLayerName = new wxTextCtrl(panDialogElements, wxID_ANY, "New Layer");
				sizFlexGrid->Add(
					txtLayerName,
					1,
					wxEXPAND
				);

				auto lblLayerType = new wxStaticText(panDialogElements, wxID_ANY, "Layer type:");
				sizFlexGrid->Add(
					lblLayerType,
					0,
					wxALIGN_CENTER_VERTICAL
				);

				auto cmbLayerType = new wxChoice(panDialogElements, wxID_ANY);
				cmbLayerType->Append(wxArrayString{
					"Tile layer",
					"Object layer",
					"Geometry layer"
				});
				cmbLayerType->Select(0);
				sizFlexGrid->Add(
					cmbLayerType,
					1,
					wxEXPAND
				);
			}

			chkMatchMapSize = new wxCheckBox(panDialogElements, wxID_ANY, "Match map size");
			chkMatchMapSize->SetValue(true);
			sizDialogElements->Add(
				chkMatchMapSize,
				0,
				wxTOP,
				borderSize * 2
			);
			chkMatchMapSize->Bind(wxEVT_CHECKBOX, &DlgNewLayer::OnCheckBoxMatchMapSize, this);

			auto sizBox2 = new wxBoxSizer(wxHORIZONTAL);
			sizDialogElements->Add(
				sizBox2,
				1,
				wxEXPAND | wxTOP,
				borderSize
			);
			{
				auto boxLayerSize = new wxStaticBox(panDialogElements, wxID_ANY, "Layer Size");
				sizBox2->Add(
					boxLayerSize,
					1,
					wxEXPAND | wxRIGHT,
					halfBorderSize
				);
				{
					auto sizBox3 = new wxBoxSizer(wxHORIZONTAL);
					boxLayerSize->SetSizer(sizBox3);
					{
						auto sizFlexGrid2 = new wxFlexGridSizer(2, 2, borderSize, hGapSize);
						sizFlexGrid2->AddGrowableCol(1, 1);
						sizBox3->Add(
							sizFlexGrid2,
							1,
							wxALIGN_CENTER_VERTICAL | wxLEFT | wxRIGHT | wxTOP,
							borderSize
						);
						{
							auto lblWidth = new wxStaticText(boxLayerSize, wxID_ANY, "Width:");
							sizFlexGrid2->Add(
								lblWidth,
								0,
								wxALIGN_CENTER_VERTICAL | wxLEFT,
								borderSize
							);

							spnLayerWidth = new wxSpinCtrl(boxLayerSize, wxID_ANY, "25");
							spnLayerWidth->SetMin(MAP_MIN_WIDTH);
							spnLayerWidth->SetMax(MAP_MAX_WIDTH);
							spnLayerWidth->Enable(false);
							sizFlexGrid2->Add(
								spnLayerWidth,
								1,
								wxEXPAND | wxRIGHT,
								borderSize
							);

							auto lblHeight = new wxStaticText(boxLayerSize, wxID_ANY, "Height:");
							sizFlexGrid2->Add(
								lblHeight,
								0,
								wxALIGN_CENTER_VERTICAL | wxLEFT,
								borderSize
							);

							spnLayerHeight = new wxSpinCtrl(boxLayerSize, wxID_ANY, "25");
							spnLayerHeight->SetMin(MAP_MIN_HEIGHT);
							spnLayerHeight->SetMax(MAP_MAX_HEIGHT);
							spnLayerHeight->Enable(false);
							sizFlexGrid2->Add(
								spnLayerHeight,
								1,
								wxEXPAND | wxRIGHT,
								borderSize
							);
						}
					}
				}

				auto boxLayerOffset = new wxStaticBox(panDialogElements, wxID_ANY, "Layer Offset");
				sizBox2->Add(
					boxLayerOffset,
					1,
					wxEXPAND | wxLEFT,
					halfBorderSize
				);
				{
					auto sizBox4 = new wxBoxSizer(wxHORIZONTAL);
					boxLayerOffset->SetSizer(sizBox4);
					{
						auto sizFlexGrid3 = new wxFlexGridSizer(2, 2, borderSize, hGapSize);
						sizFlexGrid3->AddGrowableCol(1, 1);
						sizBox4->Add(
							sizFlexGrid3,
							1,
							wxALIGN_CENTER_VERTICAL | wxLEFT | wxRIGHT | wxTOP,
							borderSize
						);
						{
							auto lblLeft = new wxStaticText(boxLayerOffset, wxID_ANY, "Left:");
							sizFlexGrid3->Add(
								lblLeft,
								0,
								wxALIGN_CENTER_VERTICAL | wxLEFT,
								borderSize
							);

							spnOffsetLeft = new wxSpinCtrl(boxLayerOffset, wxID_ANY, "0");
							spnOffsetLeft->SetMin(0);
							spnOffsetLeft->SetMax(1000);  // TODO: get from map size
							spnOffsetLeft->Enable(false);
							sizFlexGrid3->Add(
								spnOffsetLeft,
								1,
								wxEXPAND | wxRIGHT,
								borderSize
							);

							auto lblTop = new wxStaticText(boxLayerOffset, wxID_ANY, "Top:");
							sizFlexGrid3->Add(
								lblTop,
								0,
								wxALIGN_CENTER_VERTICAL | wxLEFT,
								borderSize
							);

							spnOffsetTop = new wxSpinCtrl(boxLayerOffset, wxID_ANY, "0");
							spnOffsetTop->SetMin(0);
							spnOffsetTop->SetMax(1000);  // TODO: get from map size
							spnOffsetTop->Enable(false);
							sizFlexGrid3->Add(
								spnOffsetTop,
								1,
								wxEXPAND | wxRIGHT,
								borderSize
							);
						}
					}
				}
			}
		}
	}

	auto sizDialogButtons = new wxBoxSizer(wxHORIZONTAL);
	sizRoot->Add(
		sizDialogButtons,
		0,
		wxALIGN_RIGHT
	);
	{
		auto btnOk = new wxButton(this, wxID_OK, "OK", wxDefaultPosition, FromDIP(wxSize(GUI_DEFAULT_BUTTON_WIDTH, GUI_DEFAULT_BUTTON_HEIGHT)));
		sizDialogButtons->Add(
			btnOk,
			0,
			wxRIGHT | wxBOTTOM,
			borderSize
		);

		auto btnCancel = new wxButton(this, wxID_CANCEL, "Cancel", wxDefaultPosition, FromDIP(wxSize(GUI_DEFAULT_BUTTON_WIDTH, GUI_DEFAULT_BUTTON_HEIGHT)));
		sizDialogButtons->Add(
			btnCancel,
			0,
			wxRIGHT | wxBOTTOM,
			borderSize
		);
	}

	SetSizerAndFit(sizRoot);
}