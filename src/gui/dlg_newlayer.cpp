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

kiwi::DlgNewLayer::DlgNewLayer(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "Create a New Layer", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	const int borderSize = FromDIP(GUI_DEFAULT_BORDER_SIZE);
	const int hGapSize = FromDIP(GUI_DEFAULT_GRID_HORIZONTAL_GAP);
	const int groupBoxVerticalSpacing = FromDIP(GUI_GROUP_BOX_VERTICAL_SPACING);

	auto sizRoot = new wxBoxSizer(wxVERTICAL); // root sizer

	auto panDialogElements = new wxPanel(this, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(400, 200)));
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

			auto boxLayerSize = new wxStaticBox(panDialogElements, wxID_ANY, "Layer Size");
			sizDialogElements->Add(
				boxLayerSize,
				1,
				wxEXPAND | wxTOP,
				borderSize
			);
			{
				auto sizBox1 = new wxBoxSizer(wxVERTICAL);
				boxLayerSize->SetSizer(sizBox1);
				{
					auto sizBox2 = new wxBoxSizer(wxVERTICAL);
					sizBox1->Add(
						sizBox2,
						0,
						wxEXPAND | wxTOP,
						groupBoxVerticalSpacing
					);
					{
						auto chkMatchMapSize = new wxCheckBox(boxLayerSize, wxID_ANY, "Match map size");
						chkMatchMapSize->SetValue(true);
						sizBox2->Add(
							chkMatchMapSize,
							0,
							wxLEFT,
							borderSize
						);
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