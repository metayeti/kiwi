////////////////////////////////////////////////////////////////////////////////
///   __    __         __ 
///  |  | _|__|_  _  _|__|   Kit for Interactive World Integration
///  |  |/ /  \ \/ \/ /  |   A 2D game map editor
///  |    <|  |\  _  /|  |   ( version 0.0.2 )
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
///  About dialog header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_DLG_ABOUT_H_
#define KIWI_DLG_ABOUT_H_

namespace kiwi
{
	class DlgAbout : public wxDialog
	{
	private:
		char c = 0;

		////////////////////////////////////////////////////////////////////////
		//
		//  Dialog components
		//
		////////////////////////////////////////////////////////////////////////

		wxStaticBitmap* bmpIcon;

		////////////////////////////////////////////////////////////////////////
		// 
		//  Dialog events
		// 
		////////////////////////////////////////////////////////////////////////

		void OnDoubleClickBmpIcon(wxMouseEvent& e);

	public:
		DlgAbout(wxWindow* parent);
	};
}

#endif // KIWI_DLG_ABOUT_H_