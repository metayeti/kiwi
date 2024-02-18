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
///  dlg_about.cpp
///  ---
///  About dialog implementation. The commented remarks in this source file also
///  serve as a basic reference for dialog code style used across the codebase.
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_about.h"
#include "../util.h"
#include "../const.h"

// -- resources --
#include "../res/xpm/kiwi.xpm"

kiwi::DlgAbout::DlgAbout(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "About kiwi", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	const int borderSize = FromDIP(GUI_DEFAULT_BORDER_SIZE); // first define border size based on system DPI

	auto sizRoot = new wxBoxSizer(wxVERTICAL); // this is the root sizer

	// create a "dialog elements" sizer
	auto sizDialogElements = new wxBoxSizer(wxHORIZONTAL); // use auto when creating elements on the fly
	sizRoot->Add( // always expand the arguments of Add() for visibility
		sizDialogElements,
		0,
		wxEXPAND,
		borderSize
	);
	  // use scope to indicate inner elements
	{ // (technically this achieves nothing, but it's a handy stylistic choice to make code navigation easier)

		// create an element - in this case, the kiwi program icon
		auto bmpIcon = new wxStaticBitmap(this, wxID_ANY, Util::XPMToBitmapBundle(kiwi_xpm, 64, 64));
		// -> if there are properties to apply to the created element, ideally set them here <-
		sizDialogElements->Add( // make the Add call the last in line within block for the most recently created element
			bmpIcon,
			0,
			wxALL,
			borderSize
		); // leave blank lines between elements

		// create another element, in this case the dialog text
		auto sizText = CreateTextSizer(
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
		);
		sizDialogElements->Add( // always expand Add() for visibility
			sizText,
			0,
			wxALL,
			borderSize
		);
	}

	// create a "dialog buttons" sizer
	auto sizDialogButtons = new wxBoxSizer(wxHORIZONTAL);
	sizRoot->Add( // yes, i am going to keep reminding you to expand Add()
		sizDialogButtons,
		0,
		wxALIGN_RIGHT
	);
	{ // again we use scope to indicate inner components

		// create a button element
		auto btnOkay = new wxButton(this, wxID_OK, "Okay", wxDefaultPosition, FromDIP(wxSize(GUI_DEFAULT_BUTTON_WIDTH, GUI_DEFAULT_BUTTON_HEIGHT)));
		sizDialogButtons->Add( // what did we say about expanding Add()?
			btnOkay,
			0,
			wxEXPAND | wxRIGHT | wxBOTTOM | wxTOP,
			borderSize
		);
	}

	SetSizerAndFit(sizRoot); // fit everything only _after_ the entire dialog and all of its components have been created
}