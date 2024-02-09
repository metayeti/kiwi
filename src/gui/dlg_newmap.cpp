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
		auto sizBox = new wxBoxSizer(wxVERTICAL);
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

		cmbMapSubtype = new wxChoice(panDialogElements, wxID_ANY, wxDefaultPosition, wxDefaultSize);
		cmbMapSubtype->Append(std::vector<wxString>{
			"Staggered",
			"Diamond"
		});
		cmbMapSubtype->Select(0);
		cmbMapSubtype->Hide();
		
		sizMapType->Add(
			cmbMapType,
			2,
			wxEXPAND,
			halfBorderSize
		);
		sizMapType->Add(
			cmbMapSubtype,
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

		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ORTHOGONAL, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ISOMETRIC_STAGGERED, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_ISOMETRIC_DIAMOND, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE1_STAGGERED, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE1_DIAMOND, wxSize(128, 64)));
		//auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE2_STAGGERED, wxSize(128, 64)));
		auto bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, wxBitmapBundle::FromSVG(SVG_GRAPHIC_MAPTYPE_HEXAGONAL_TYPE2_DIAMOND, wxSize(128, 64)));

		//bmpIcon->SetBackgroundColour(wxColour(*wxWHITE));

		sizBox->Add(
			bmpIcon,
			0,
			wxALIGN_CENTER | wxTOP,
			borderSize
		);

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

	SetSizerAndFit(sizRoot);
}

void kiwi::DlgNewMap::OnChoiceMapType(wxCommandEvent& e)
{
	if (cmbMapType->GetSelection() == 0)
	{
		// orthogonal map type
		cmbMapSubtype->Hide();
		sizMapType->Layout();
	}
	else
	{
		// non-orthogonal map type
		cmbMapSubtype->Show();
		sizMapType->Layout();
	}
	//this->Fit();
}