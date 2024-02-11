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

	int mapTypeSelection = cmbMapType->GetSelection();
	int mapSubtypeSelection = cmbMapIsoSubtype->GetSelection();
	int mapHexTypeSelection = cmbMapHexSubtype->GetSelection();

	switch (mapTypeSelection)
	{
		case 0: // orthogonal map type
			vecBmpGraphic[0]->Show();

			break;

		case 1: // isometric map type
			switch (mapSubtypeSelection)
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

			switch (mapHexTypeSelection)
			{
			case 0: // hex type 1
				vecBmpGraphic[3]->Show();
				break;
			case 1: // hex type 2
				vecBmpGraphic[4]->Show();
				break;
			}

			break;
	}

	sizBox->Layout();

	/*
	if (mapTypeSelection == 0)
	{
		// orthogonal map type
		vecBmpGraphic[0]->Show();
	}
	else if (mapTypeSelection == 1)
	{
		// isometric map type
		if (mapSubtypeSelection == 0) {
			vecBmpGraphic[1]->Show();
		}
		else if (mapSubtypeSelection == 1) {
			vecBmpGraphic[2]->Show();
		}
	}
	else if (mapTypeSelection == 2)
	{
		// hexagonal map type

	}
	*/
}

void kiwi::DlgNewMap::OnChoiceMapType(wxCommandEvent& e)
{
	int mapTypeSelection = cmbMapType->GetSelection();
	if (mapTypeSelection == 0)
	{
		// orthogonal map type
		cmbMapHexSubtype->Hide();
		cmbMapIsoSubtype->Hide();
	}
	else if (mapTypeSelection == 1)
	{
		// isometric map type
		cmbMapHexSubtype->Hide();
		cmbMapIsoSubtype->Show();
	}
	else if (mapTypeSelection == 2) {
		// hexagonal map type
		cmbMapHexSubtype->Show();
		cmbMapIsoSubtype->Hide();
	}
	sizMapType->Layout();
	//this->Fit();

	UpdateMapGraphic();
}

void kiwi::DlgNewMap::OnChoiceMapHexType(wxCommandEvent& e)
{
	UpdateMapGraphic();
}

void kiwi::DlgNewMap::OnChoiceMapSubtype(wxCommandEvent& e)
{
	UpdateMapGraphic();
}

kiwi::DlgNewMap::DlgNewMap(wxWindow* parent)
//: wxDialog(parent, wxID_ANY, "Create a New Map", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
	: wxDialog(parent, wxID_ANY, "Create a New Map", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER) //TODO remove, just for testing
{
	const int borderSize = FromDIP(GUI_DEFAULT_BORDER_SIZE);
	const int halfBorderSize = FromDIP(GUI_HALF_BORDER_SIZE);

	auto sizRoot = new wxBoxSizer(wxVERTICAL);

	auto panDialogElements = new wxPanel(this, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(400, 250)));
	sizRoot->Add(
		panDialogElements,
		1,
		wxEXPAND | wxALL,
		borderSize
	);
	{
		sizBox = new wxBoxSizer(wxVERTICAL);
		panDialogElements->SetSizer(sizBox);

		sizGrid = new wxFlexGridSizer(2, 2, FromDIP(10), FromDIP(25));

		auto lblMapName = new wxStaticText(panDialogElements, wxID_ANY, "Map &name:");

		auto lblMapType = new wxStaticText(panDialogElements, wxID_ANY, "Grid &type:");

		auto txtMapName = new wxTextCtrl(panDialogElements, wxID_ANY, "Untitled");

		sizMapType = new wxBoxSizer(wxHORIZONTAL);

		cmbMapType = new wxChoice(panDialogElements, wxID_ANY, wxDefaultPosition, wxDefaultSize);
		cmbMapType->Append(std::vector<wxString>{
			"Orthogonal",
				"Isometric",
				"Hexagonal"
		});
		cmbMapType->Select(0);
		Bind(wxEVT_CHOICE, &DlgNewMap::OnChoiceMapType, this, cmbMapType->GetId());

		cmbMapHexSubtype = new wxChoice(panDialogElements, wxID_ANY, wxDefaultPosition, wxDefaultSize);
		cmbMapHexSubtype->Append(std::vector<wxString>{
			"Type 1",
				"Type 2"
		});
		cmbMapHexSubtype->Select(0);
		cmbMapHexSubtype->Hide();
		Bind(wxEVT_CHOICE, &DlgNewMap::OnChoiceMapHexType, this, cmbMapHexSubtype->GetId());

		cmbMapIsoSubtype = new wxChoice(panDialogElements, wxID_ANY, wxDefaultPosition, wxDefaultSize);
		cmbMapIsoSubtype->Append(std::vector<wxString>{
			"Staggered",
				"Diamond"
		});
		cmbMapIsoSubtype->Select(0);
		cmbMapIsoSubtype->Hide();
		Bind(wxEVT_CHOICE, &DlgNewMap::OnChoiceMapSubtype, this, cmbMapIsoSubtype->GetId());

		sizMapType->Add(
			cmbMapType,
			2,
			wxEXPAND,
			halfBorderSize
		);
		sizMapType->Add(
			cmbMapHexSubtype,
			1,
			wxLEFT,
			borderSize
		);
		sizMapType->Add(
			cmbMapIsoSubtype,
			1,
			wxLEFT,
			borderSize
		);

		sizGrid->Add(
			lblMapName,
			0,
			wxALIGN_CENTER_VERTICAL
		);
		sizGrid->Add(
			txtMapName,
			1,
			wxEXPAND
		);
		sizGrid->Add(
			lblMapType,
			0,
			wxALIGN_CENTER_VERTICAL
		);
		sizGrid->Add(
			//cmbMapType,
			sizMapType,
			1,
			wxEXPAND
		);

		sizGrid->AddGrowableCol(1, 1);

		sizBox->Add(
			sizGrid,
			0,
			wxEXPAND
		);

		//vecBmpGraphic = {
		vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ORTHOGONAL, wxSize(128, 64))));
		vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ISOMETRIC_STAGGERED, wxSize(128, 64))));
		vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ISOMETRIC_DIAMOND, wxSize(128, 64))));
		vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE1, wxSize(128, 64))));
		vecBmpGraphic.push_back(new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE2, wxSize(128, 64))));
		//};

		for (const auto bmpComponent : vecBmpGraphic)
		{
			bmpComponent->Hide();

			sizBox->Add(
				bmpComponent,
				0,
				wxALIGN_CENTER | wxTOP,
				borderSize
			);
		}


		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ORTHOGONAL, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ISOMETRIC_STAGGERED, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ISOMETRIC_DIAMOND, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE1_STAGGERED, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE1_DIAMOND, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE2_STAGGERED, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE2_DIAMOND, wxSize(128, 64)));

		//bmpIcon->SetBackgroundColour(wxColour(*wxWHITE));

		/*
		sizBox->Add(
			vecBmpGraphic[0],
			0,
			wxALIGN_CENTER | wxTOP,
			borderSize
		);
		*/

		auto hSizer = new wxBoxSizer(wxHORIZONTAL);

		auto box1 = new wxStaticBox(panDialogElements, wxID_ANY, "Map Size");

		auto box2 = new wxStaticBox(panDialogElements, wxID_ANY, "Grid Size");

		hSizer->Add(
			box1,
			1,
			wxRIGHT | wxEXPAND,
			FromDIP(5)
		);

		hSizer->Add(
			box2,
			1,
			wxLEFT | wxEXPAND,
			FromDIP(5)
		);

		sizBox->Add(
			hSizer,
			1,
			wxEXPAND
			//wxTOP | wxEXPAND,
			//borderSize
		);
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