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

kiwi::DlgNewMap::DlgNewMap(wxWindow* parent)
//: wxDialog(parent, wxID_ANY, "Create a New Map", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
: wxDialog(parent, wxID_ANY, "Create a New Map", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER) //TODO remove, just for testing
{
	const int borderSize = FromDIP(GUI_DEFAULT_BORDER_SIZE);
	const int halfBorderSize = FromDIP(GUI_HALF_BORDER_SIZE);

	auto sizRoot = new wxBoxSizer(wxVERTICAL);

	auto panDialogElements = new wxPanel(this, wxID_ANY, wxDefaultPosition, FromDIP(wxSize(400, 200)));
	sizRoot->Add(
		panDialogElements,
		1,
		wxEXPAND | wxALL,
		borderSize
	);
	{
		auto vSizer = new wxBoxSizer(wxVERTICAL);
		panDialogElements->SetSizer(vSizer);

		auto fgSizer = new wxFlexGridSizer(2, 2, FromDIP(10), FromDIP(25));

		wxStaticText* lblMapName = new wxStaticText(panDialogElements, wxID_ANY, wxT("Map &name:"));

		wxStaticText* lblMapType = new wxStaticText(panDialogElements, wxID_ANY, wxT("Grid &type:"));

		wxTextCtrl* txtMapName = new wxTextCtrl(panDialogElements, wxID_ANY, wxT("Unnamed"));
		wxChoice* cmbMapType = new wxChoice(panDialogElements, wxID_ANY);
		cmbMapType->Append(std::vector<wxString>{
			"Orthogonal",
			"Isometric (Staggered)",
			"Isometric (Diamond)",
			"Hexagonal (Staggered)",
			"Hexagonal (Diamond)"
		});
		cmbMapType->Select(0);

		fgSizer->Add(
			lblMapName,
			0,
			wxALIGN_CENTER_VERTICAL
		);
		fgSizer->Add(
			txtMapName,
			1,
			wxEXPAND
		);
		fgSizer->Add(
			lblMapType,
			0,
			wxALIGN_CENTER_VERTICAL
		);
		fgSizer->Add(
			cmbMapType,
			1,
			wxEXPAND
		);

		fgSizer->AddGrowableCol(1, 1);

		vSizer->Add(
			fgSizer,
			0,
			wxEXPAND
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

		vSizer->Add(
			hSizer,
			1,
			wxTOP | wxEXPAND,
			borderSize
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