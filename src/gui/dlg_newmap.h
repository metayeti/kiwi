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

#ifndef KIWI_DLG_NEWMAP_H_
#define KIWI_DLG_NEWMAP_H_

namespace kiwi
{
	class DlgNewMap : public wxDialog
	{
	private:
		////////////////////////////////////////////////////////////////////////
		//
		//  Dialog components
		//
		////////////////////////////////////////////////////////////////////////

		wxBoxSizer* sizDialogElements;
		wxBoxSizer* sizBox1;
		wxChoice* cmbGridType;
		wxChoice* cmbIsoGridType;
		wxChoice* cmbHexGridType;

		wxVector<wxStaticBitmap*> vecBmpGraphic;

		////////////////////////////////////////////////////////////////////////
		//
		//  Dialog actions
		//
		////////////////////////////////////////////////////////////////////////

		void UpdateMapGraphic();

		////////////////////////////////////////////////////////////////////////
		// 
		//  Events
		// 
		////////////////////////////////////////////////////////////////////////

		// menubar events
		void OnChoiceGridType(wxCommandEvent& e);
		void OnChoiceIsoGridType(wxCommandEvent& e);
		void OnChoiceHexGridType(wxCommandEvent& e);

	public:
		DlgNewMap(wxWindow* parent);
	};
}

#endif // KIWI_DLG_NEWMAP_H_