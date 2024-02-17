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
///  dlg_newmap.cpp
///  ---
///  New map dialog implementation.
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_newmap.h"
#include "../const.h"
#include "../res/svg_resources.h"

void kiwi::DlgNewMap::UpdateMapGraphic()
{
	
	for (const auto bmpComponent : vecBmpGraphic)
	{
		bmpComponent->Hide();
	}

	int gridType = cmbGridType->GetSelection();
	int isoGridType = cmbIsoGridType->GetSelection();
	int hexGridType = cmbHexGridType->GetSelection();

	switch (gridType)
	{
		case 0: // orthogonal map type
			vecBmpGraphic[0]->Show();
			break;

		case 1: // isometric map type
			switch (isoGridType)
			{
				case 0: // staggered type
					vecBmpGraphic[1]->Show();
					break;
				case 1: // diamond type
					vecBmpGraphic[2]->Show();
					break;
			}

			break;

		case 2: // hexagonal map type

			switch (hexGridType)
			{
			case 0: // flat-top type
				vecBmpGraphic[3]->Show();
				break;
			case 1: // pointy-top type
				vecBmpGraphic[4]->Show();
				break;
			}

			break;
	}

	sizDialogElements->Layout();
	
}

void kiwi::DlgNewMap::OnChoiceGridType(wxCommandEvent& e)
{
	int gridType = cmbGridType->GetSelection();
	if (gridType == 0)
	{
		// orthogonal map type
		cmbIsoGridType->Hide();
		cmbHexGridType->Hide();
	}
	else if (gridType == 1)
	{
		// isometric map type
		cmbIsoGridType->Show();
		cmbHexGridType->Hide();
	}
	else if (gridType == 2) {
		// hexagonal map type
		cmbIsoGridType->Hide();
		cmbHexGridType->Show();
	}
	sizBox1->Layout();
	//this->Fit();

	UpdateMapGraphic();
}

void kiwi::DlgNewMap::OnChoiceIsoGridType(wxCommandEvent& e)
{
	UpdateMapGraphic();
}

void kiwi::DlgNewMap::OnChoiceHexGridType(wxCommandEvent& e)
{
	UpdateMapGraphic();
}

kiwi::DlgNewMap::DlgNewMap(wxWindow* parent)
//: wxDialog(parent, wxID_ANY, "Create a New Map", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
	: wxDialog(parent, wxID_ANY, "Create a New Map", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER) //TODO remove, just for testing
{
	const int borderSize = FromDIP(GUI_DEFAULT_BORDER_SIZE);
	const int halfBorderSize = FromDIP(GUI_HALF_BORDER_SIZE);
	const int hGap = FromDIP(GUI_DEFAULT_GRID_HORIZONTAL_GAP);

	auto sizRoot = new wxBoxSizer(wxVERTICAL); // root sizer

	auto panDialogElements = new wxPanel(this, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(400, 250)));
	sizRoot->Add(
		panDialogElements,
		1,
		wxEXPAND | wxALL,
		borderSize
	);
	{
		sizDialogElements = new wxBoxSizer(wxVERTICAL);
		panDialogElements->SetSizer(sizDialogElements);
		{
			auto sizFlexGrid = new wxFlexGridSizer(2, 2, borderSize, FromDIP(25));
			sizFlexGrid->AddGrowableCol(1, 1);
			sizDialogElements->Add(
				sizFlexGrid,
				0,
				wxEXPAND
			);
			{
				auto lblMapName = new wxStaticText(panDialogElements, wxID_ANY, "Map name:");
				sizFlexGrid->Add(
					lblMapName,
					0,
					wxALIGN_CENTER_VERTICAL
				);

				auto txtMapName = new wxTextCtrl(panDialogElements, wxID_ANY, "Untitled");
				sizFlexGrid->Add(
					txtMapName,
					1,
					wxEXPAND
				);

				auto lblGridType = new wxStaticText(panDialogElements, wxID_ANY, "Grid type:");
				sizFlexGrid->Add(
					lblGridType,
					0,
					wxALIGN_CENTER_VERTICAL
				);

				sizBox1 = new wxBoxSizer(wxHORIZONTAL);
				sizFlexGrid->Add(
					sizBox1,
					0,
					wxEXPAND
				);
				{
					cmbGridType = new wxChoice(panDialogElements, wxID_ANY);
					cmbGridType->Append(wxArrayString{
						"Orthogonal",
						"Isometric",
						"Hexagonal"
					});
					cmbGridType->Select(0);
					Bind(wxEVT_CHOICE, &DlgNewMap::OnChoiceGridType, this, cmbGridType->GetId());
					sizBox1->Add(
						cmbGridType,
						2,
						wxEXPAND
					);

					cmbIsoGridType = new wxChoice(panDialogElements, wxID_ANY);
					cmbIsoGridType->Append(wxArrayString{
						"Staggered",
						"Diamond"
					});
					cmbIsoGridType->Select(0);
					cmbIsoGridType->Hide();
					Bind(wxEVT_CHOICE, &DlgNewMap::OnChoiceIsoGridType, this, cmbIsoGridType->GetId());
					sizBox1->Add(
						cmbIsoGridType,
						1,
						wxLEFT,
						borderSize
					);

					cmbHexGridType = new wxChoice(panDialogElements, wxID_ANY);
					cmbHexGridType->Append(wxArrayString{
						"Flat-top",
						"Pointy-top"
					});
					cmbHexGridType->Select(0);
					cmbHexGridType->Hide();
					Bind(wxEVT_CHOICE, &DlgNewMap::OnChoiceHexGridType, this, cmbHexGridType->GetId());
					sizBox1->Add(
						cmbHexGridType,
						1,
						wxLEFT,
						borderSize
					);
				}
			}

			vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_GRIDTYPE_ORTHOGONAL, wxSize(128, 64))));
			vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_GRIDTYPE_ISOMETRIC_STAGGERED, wxSize(128, 64))));
			vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_GRIDTYPE_ISOMETRIC_DIAMOND, wxSize(128, 64))));
			vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_GRIDTYPE_HEXAGONAL_FLAT_TOP, wxSize(128, 64))));
			vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_GRIDTYPE_HEXAGONAL_POINTY_TOP, wxSize(128, 64))));

			for (const auto bmpComponent : vecBmpGraphic)
			{
				bmpComponent->Hide();
				sizDialogElements->Add(
					bmpComponent,
					0,
					wxALIGN_CENTER | wxTOP,
					borderSize
				);
			}

			auto sizBox2 = new wxBoxSizer(wxHORIZONTAL);
			sizDialogElements->Add(
				sizBox2,
				1,
				wxEXPAND
			);
			{
				auto box1 = new wxStaticBox(panDialogElements, wxID_ANY, "Map Size");
				sizBox2->Add(
					box1,
					1,
					wxRIGHT | wxEXPAND,
					halfBorderSize
				);

				auto box2 = new wxStaticBox(panDialogElements, wxID_ANY, "Grid Size");
				sizBox2->Add(
					box2,
					1,
					wxLEFT | wxEXPAND,
					halfBorderSize
				);
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
			wxEXPAND | wxRIGHT | wxBOTTOM,
			borderSize
		);

		auto btnCancel = new wxButton(this, wxID_CANCEL, "Cancel", wxDefaultPosition, FromDIP(wxSize(GUI_DEFAULT_BUTTON_WIDTH, GUI_DEFAULT_BUTTON_HEIGHT)));
		sizDialogButtons->Add(
			btnCancel,
			0,
			wxEXPAND | wxRIGHT | wxBOTTOM,
			borderSize
		);
	}

	UpdateMapGraphic();

	SetSizerAndFit(sizRoot);
}