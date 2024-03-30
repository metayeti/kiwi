////////////////////////////////////////////////////////////////////////////////
///   __    __         __ 
///  |  | _|__|_  _  _|__|   Kit for Interactive World Integration
///  |  |/ /  \ \/ \/ /  |   A 2D game map editor
///  |    <|  |\  _  /|  |   ( version 0.0.3 dev )
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
///  dlg_about.cpp
///  ---
///  About dialog implementation. Also serves as a sort of quick rundown on
///  dialog coding stye in this codebase.
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_about.h"
#include "../util.h"
#include "../const.h"
#include "dlg_game.h"

// -- resources --
#include "../res/xpm/kiwi.xpm"

void kiwi::DlgAbout::OnDoubleClickBmpIcon(wxMouseEvent& e)
{
	///if (++(this->c) <3) return;
	///this->c = 0;

	//
	// ,.-~` easter egg `~-.,
	//

	// open the game window
	auto dlgGame = new DlgGame(this);
	dlgGame->CenterOnParent();
	dlgGame->ShowModal();
}

kiwi::DlgAbout::DlgAbout(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "About kiwi", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	const int borderSize = FromDIP(GUI_DEFAULT_BORDER_SIZE); // first define border size based on system DPI

	auto sizRoot = new wxBoxSizer(wxVERTICAL); // this is the root sizer

	// always create a panel that holds all dialog elements (apart from the bottom-row buttons)
	auto panDialogElements = new wxPanel(this, wxID_ANY); // use auto when creating anonymous elements
	sizRoot->Add(
		panDialogElements,
		1,
		wxEXPAND | wxALL,
		borderSize
	);
	// create a "dialog elements" sizer
	auto sizDialogElements = new wxBoxSizer(wxHORIZONTAL);
	panDialogElements->SetSizer(sizDialogElements);
	  // use scope to indicate inner elements
	{ // (technically this achieves nothing (sort of*), but it's a handy stylistic choice to make code navigation easier)
	  //
	  // (* it allows creation of (anonymous) elements of same name in different containers)

		// create an element - in this case, the kiwi program icon
		bmpIcon = new wxStaticBitmap(panDialogElements, wxID_ANY, Util::XPMToBitmapBundle(kiwi_xpm, 64, 64));
		// -> if there are properties to apply to the created element, ideally set them here <-
		// bind any events at this point
		bmpIcon->Bind(wxEVT_LEFT_DCLICK, &DlgAbout::OnDoubleClickBmpIcon, this);
		// finally, add element to a sizer
		sizDialogElements->Add( // make the Add call the last in line within block for the most recently created element
			bmpIcon,
			0,
			wxRIGHT,
			borderSize
		); // leave blank lines between elements

		// create another element, in this case the dialog text label
		auto lblAbout = new wxStaticText(panDialogElements, wxID_ANY, (
			"kiwi\n"
			"Kit for Interactive World Integration\n\n"
			"v" + wxString(KIWI_VERSION) + " "
#if defined(KIWI_SYSTEM_WINDOWS)
			"Windows"
#elif defined(KIWI_SYSTEM_LINUX)
			"Linux"
#elif defined(KIWI_SYSTEM_MACOS)
			"MacOS"
#endif
			" build"
#if defined(KIWI_DEBUG_BUILD)
			" (debug)"
#endif
			"\n\n"
			"Copyright " + wxString::FromUTF8("\xc2\xa9") + " 2024 Danijel Durakovic\n"
			"Licensed under the terms of GPLv3"
		));
		sizDialogElements->Add( // always expand Add() for visibility
			lblAbout,
			0,
			wxLEFT,
			borderSize
		);
	}

	// create a "dialog buttons" sizer
	auto sizDialogButtons = new wxBoxSizer(wxHORIZONTAL);
	// (here we use just the sizer directly, without the panel, so we add it to the root sizer)
	sizRoot->Add( // i am going to keep reminding you to expand Add() to multiple lines
		sizDialogButtons,
		0,
		wxALIGN_RIGHT
	);
	{ // once more we use scope to indicate inner components

		// create a button element
		auto btnOkay = new wxButton(this, wxID_OK, "Okay", wxDefaultPosition, FromDIP(wxSize(GUI_DEFAULT_BUTTON_WIDTH, GUI_DEFAULT_BUTTON_HEIGHT)));
		sizDialogButtons->Add( // remember that thing we said about expanding Add() to multiple lines?
			btnOkay,
			0,
			wxEXPAND | wxRIGHT | wxBOTTOM | wxTOP,
			borderSize
		);
	}

	SetSizerAndFit(sizRoot); // fit everything only _after_ the entire dialog and all of its components have been created
}