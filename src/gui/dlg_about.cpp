////////////////////////////////////////////////////////////////////////////////
///   __    __         __ 
///  |  | _|__|_  _  _|__|   Kit for Interactive World Integration
///  |  |/ /  \ \/ \/ /  |   A 2D game map editor
///  |    <|  |\  _  /|  |   ( version 0.0.1 )
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
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_about.h"
#include "../util.h"
#include "../const.h"

// -- xpm resources --
#include "../res/xpm/kiwi.xpm"

kiwi::DlgAbout::DlgAbout(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "About kiwi", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	wxBoxSizer* outerVSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* innerHSizer = new wxBoxSizer(wxHORIZONTAL);

	const int borderSize = FromDIP(10);

	wxStaticBitmap* bmpLogo = new wxStaticBitmap(this, wxID_ANY, Util::XPMToBitmapBundle(kiwi_xpm, 64, 64));

	innerHSizer->Add(bmpLogo, 0, wxALL, borderSize);

	// text info
	innerHSizer->Add(
		CreateTextSizer(
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
		),
		0,
		wxALL,
		borderSize
	);

	outerVSizer->Add(innerHSizer);

	// ok button
	outerVSizer->Add(new wxButton(this, wxID_OK, "Okay", wxDefaultPosition, FromDIP(wxSize(110, 30))), 0, wxTOP | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, borderSize);

	SetSizerAndFit(outerVSizer);
}