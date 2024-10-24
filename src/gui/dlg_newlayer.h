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
///  dlg_newlayer.h
///  ---
///  New layer dialog header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_DLG_NEWLAYER_H_
#define KIWI_DLG_NEWLAYER_H_

namespace kiwi
{
	class DlgNewLayer : public wxDialog
	{
	private:
		////////////////////////////////////////////////////////////////////////
		// 
		//  Dialog components
		// 
		////////////////////////////////////////////////////////////////////////

		wxCheckBox* chkMatchMapSize;

		wxSpinCtrl* spnLayerWidth;
		wxSpinCtrl* spnLayerHeight;
		wxSpinCtrl* spnOffsetLeft;
		wxSpinCtrl* spnOffsetTop;

		////////////////////////////////////////////////////////////////////////
		// 
		//  Dialog actions
		// 
		////////////////////////////////////////////////////////////////////////

		void EnableDisableComponents();

		////////////////////////////////////////////////////////////////////////
		// 
		//  Dialog events
		// 
		////////////////////////////////////////////////////////////////////////

		void OnCheckBoxMatchMapSize(wxCommandEvent& e);
		
	public:
		DlgNewLayer(wxWindow* parent);
	};
}

#endif // KIWI_DLG_NEWLAYER_H_