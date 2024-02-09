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
///  dlg_newmap.h
///  ---
///  New map dialog header.
///
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_DLG_NEWMAP_H_
#define KIWI_DLG_NEWMAP_H_

namespace kiwi
{
	class DlgNewMap : public wxDialog
	{
	public:
		DlgNewMap(wxWindow* parent);

		////////////////////////////////////////////////////////////////////////
		//
		//  Frame members
		//
		////////////////////////////////////////////////////////////////////////

		wxFlexGridSizer* sizGrid;
		wxBoxSizer* sizMapType;

		wxChoice* cmbMapType;
		wxChoice* cmbMapSubtype;

		////////////////////////////////////////////////////////////////////////
		// 
		//  Events
		// 
		////////////////////////////////////////////////////////////////////////

		// menubar events
		void OnChoiceMapType(wxCommandEvent& e);
	};
}

#endif // KIWI_DLG_NEWMAP_H_