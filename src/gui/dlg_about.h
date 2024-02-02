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
///  dlg_about.h
///  ---
///  About dialog.
///
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_DLG_ABOUT_H_
#define KIWI_DLG_ABOUT_H_

namespace kiwi
{
	class DlgAbout : public wxDialog
	{
	public:
		DlgAbout(wxWindow* parent);
	};
}

#endif // KIWI_DLG_ABOUT_H_