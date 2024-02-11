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
///  frm_main.h
///  ---
///  Main frame header.
///
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_FRM_MAIN_H_
#define KIWI_FRM_MAIN_H_

namespace kiwi
{
	class FrmMain : public wxFrame
	{
	private:
		Application* application = nullptr;

		// most recent window geometry pre-maximization
		wxPoint lastWindowPosition;
		wxSize lastWindowSize;

		////////////////////////////////////////////////////////////////////////
		//
		//  Statusbar class
		//
		////////////////////////////////////////////////////////////////////////

		class StatusBar : public wxStatusBar
		{
		private:
			wxComboBox* cmbZoomLevel;

			enum
			{
				Field_Text,
				Field_Zoom,
				Field_Max
			};

			void OnSize(wxSizeEvent& e);

		public:
			StatusBar(wxWindow* parent, long style = wxSTB_DEFAULT_STYLE);
			virtual ~StatusBar();
		};

		////////////////////////////////////////////////////////////////////////
		//
		//  Menubar structure
		//
		////////////////////////////////////////////////////////////////////////

		struct MenuBar
		{
			wxMenuBar* root;

			// -- File --
			struct MenuFile
			{
				wxMenu* root;
				struct Members
				{
					wxMenuItem* menuNew;
					wxMenuItem* menuNewFromTemplate;
					wxMenuItem* menuOpen;
					struct MenuOpenRecent
					{
						wxMenu* root;
						struct MEMBERS
						{
							wxMenuItem* menuNoRecentItems;
							wxMenuItem* menuRecent[10];
						} members;
					} menuOpenRecent;
					wxMenuItem* menuSave;
					wxMenuItem* menuSaveAs;
					wxMenuItem* menuSaveCopy;
					wxMenuItem* menuSaveAll;
					wxMenuItem* menuSaveTemplate;
					wxMenuItem* menuExport;
					wxMenuItem* menuExportAs;
					wxMenuItem* menuClose;
					wxMenuItem* menuCloseAll;
					wxMenuItem* menuQuit;
				} members;
			} menuFile;

			// -- Edit --
			struct MenuEdit
			{
				wxMenu* root;
			} menuEdit;

			// -- View --
			struct MenuView
			{
				wxMenu* root;
			} menuView;

			// -- Map --
			struct MenuMap
			{
				wxMenu* root;
			} menuMap;

			// -- Layer --
			struct MenuLayer
			{
				wxMenu* root;
			} menuLayer;

			// -- Tools --
			struct MenuTools
			{
				wxMenu* root;
			} menuTools;

			// -- Help --
			struct MenuHelp
			{
				wxMenu* root;
				struct Members
				{
					wxMenuItem* menuUserManual;
					wxMenuItem* menuCheckForUpdates;
					wxMenuItem* menuAbout;
				} members;
			} menuHelp;

		} menuBar;


		////////////////////////////////////////////////////////////////////////
		//
		//  Frame components
		//
		////////////////////////////////////////////////////////////////////////
		
		StatusBar* statusBar;

		////////////////////////////////////////////////////////////////////////
		//
		//  Editor actions
		//
		////////////////////////////////////////////////////////////////////////

		//void ActionUndo();
		//void ActionRedo();


		////////////////////////////////////////////////////////////////////////
		//
		//  Events
		//
		////////////////////////////////////////////////////////////////////////

		// menubar events
		void OnMenuFileNew(wxCommandEvent& e);
		void OnMenuFileQuit(wxCommandEvent& e);

		void OnMenuHelpUserManual(wxCommandEvent& e);
		void OnMenuHelpCheckForUpdates(wxCommandEvent& e);
		void OnMenuHelpAbout(wxCommandEvent& e);

		// window events
		void OnWindowMove(wxMoveEvent& e);
		void OnWindowSize(wxSizeEvent& e);
		void OnWindowClose(wxCloseEvent& e);

		////////////////////////////////////////////////////////////////////////
		//
		//  Initialization
		//
		////////////////////////////////////////////////////////////////////////

		void InitializeGlobalMenu();
		void InitializeStatusBar();

	public:
		FrmMain(Application* application);
	};
}

#endif // KIWI_FRM_MAIN_H_
