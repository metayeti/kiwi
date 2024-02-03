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
///  frm_main.cpp
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "../const.h"
#include "../config.h"
#include "../application.h"
#include "../util.h"
#include "frm_main.h"
#include "dlg_about.h"
#include "../res/svg_resources.h"
#include "../res/xpm_resources.h"

void kiwi::FrmMain::StatusBar::OnSize(wxSizeEvent& e)
{
	wxRect rect;
	if (!GetFieldRect(Field_Zoom, rect))
	{
		e.Skip();
		return;
	}

	wxRect rectCheck = rect;
	//rectCheck.Deflate(2);
	cmbZoomLevel->SetSize(rectCheck);

	e.Skip();
}

kiwi::FrmMain::StatusBar::StatusBar(wxWindow* parent, long style)
: wxStatusBar(parent, wxID_ANY, style, "kiwi statusbar")
{
	int widths[Field_Max];
	widths[Field_Text] = -1; // growable
	widths[Field_Zoom] = 70;

	SetFieldsCount(Field_Max);
	SetStatusWidths(Field_Max, widths);

	cmbZoomLevel = new wxComboBox(this, wxID_ANY, wxEmptyString);
	cmbZoomLevel->Append(std::vector<wxString>{ "25%", "50%", "75%", "100%", "125%", "150%", "175%", "200%" });
	cmbZoomLevel->Select(3);

	SetMinHeight(cmbZoomLevel->GetMinHeight());

	Bind(wxEVT_SIZE, &FrmMain::StatusBar::OnSize, this);
}

kiwi::FrmMain::StatusBar::~StatusBar()
{
	
}

void kiwi::FrmMain::OnMenuFileNew(wxCommandEvent& e)
{
}

void kiwi::FrmMain::OnMenuFileQuit(wxCommandEvent& e)
{
	Close(false);
}

void kiwi::FrmMain::OnMenuHelpUserManual(wxCommandEvent& e)
{
	wxLaunchDefaultBrowser(URL_GITHUB_MANUAL);
}

void kiwi::FrmMain::OnMenuHelpCheckForUpdates(wxCommandEvent& e)
{
	wxLaunchDefaultBrowser(URL_GITHUB_RELEASES);
}

void kiwi::FrmMain::OnMenuHelpAbout(wxCommandEvent& e)
{
	DlgAbout* dlgAbout = new DlgAbout(this);
	dlgAbout->CenterOnParent();
	dlgAbout->ShowModal();
}

void kiwi::FrmMain::OnWindowMove(wxMoveEvent& e)
{
	if (!IsMaximized())
	{
		lastWindowPosition = GetPosition();
	}
}

void kiwi::FrmMain::OnWindowSize(wxSizeEvent& e)
{
	if (!IsMaximized())
	{
		lastWindowSize = GetSize();
	}
}

void kiwi::FrmMain::OnWindowClose(wxCloseEvent& e)
{
	// check if we have to veto
	bool fileNotSaved = false; // TODO move to class scope
	if (e.CanVeto() && fileNotSaved)
	{
		if (wxMessageBox("File has not been saved. Save now?", MAIN_WINDOW_TITLE, wxICON_EXCLAMATION | wxYES_NO | wxCANCEL) == wxYES)
		{
			e.Veto();
			return;
		}
	}

	// save config before closing
	auto* config = application->GetConfig();
	config->SetBool("startup", "center", false);
	config->SetUnsignedIntPair("startup", "position", { lastWindowPosition.x, lastWindowPosition.y });
	config->SetUnsignedIntPair("startup", "size", { lastWindowSize.x, lastWindowSize.y });
	config->SetBool("startup", "maximize", IsMaximized());
	config->Write();
	// destroy this frame
	Destroy();
}

void kiwi::FrmMain::InitializeGlobalMenu()
{
	SetMenuBar(menuBar.root = new wxMenuBar());

	// -- File --
	auto& menuFile = menuBar.menuFile;
	menuBar.root->Append((menuFile.root = new wxMenu()), "&File");
	{
		auto& menuNew = menuFile.members.menuNew;
		menuNew = new wxMenuItem(menuFile.root, wxID_ANY, "&New...\tCtrl+N", QUICKHELP_ACTION_FILE_NEW);
		///menuNew->SetBitmap(wxBitmapBundle::FromSVG(Util::GetThemeAgnosticSVG(SVG_ICON_NEW, darkMode).c_str(), wxSize(16, 16)));
		menuNew->SetBitmap(wxBitmapBundle::FromSVG(SVG_ICON_NEW, wxSize(16, 16)));
		menuFile.root->Append(menuNew);
		Bind(wxEVT_MENU, &FrmMain::OnMenuFileNew, this, menuNew->GetId());

		menuFile.root->AppendSeparator();

		auto& menuOpen = menuFile.members.menuOpen;
		menuOpen = new wxMenuItem(menuFile.root, wxID_ANY, "&Open...\tCtrl+O", QUICKHELP_ACTION_FILE_OPEN);
		menuOpen->SetBitmap(wxBitmapBundle::FromSVG(SVG_ICON_OPEN, wxSize(16, 16)));
		menuFile.root->Append(menuOpen);

		auto& menuOpenRecent = menuFile.members.menuOpenRecent;
		menuFile.root->AppendSubMenu((menuOpenRecent.root = new wxMenu()), "Open &Recent", "test");
		{
			auto& menuNoRecentItems = menuOpenRecent.members.menuNoRecentItems;
			menuNoRecentItems = new wxMenuItem(menuOpenRecent.root, wxID_ANY, "(no recent items)");
			menuOpenRecent.root->Append(menuNoRecentItems);
			menuNoRecentItems->Enable(false);

		}

		menuFile.root->AppendSeparator();

		auto& menuSave = menuFile.members.menuSave;
		menuSave = new wxMenuItem(menuFile.root, wxID_ANY, "&Save\tCtrl+S", QUICKHELP_ACTION_FILE_SAVE);
		menuSave->SetBitmap(wxBitmapBundle::FromSVG(SVG_ICON_SAVE, wxSize(16, 16)));
		menuFile.root->Append(menuSave);

		auto& menuSaveAs = menuFile.members.menuSaveAs;
		menuSaveAs = new wxMenuItem(menuFile.root, wxID_ANY, "Save &As...\tCtrl+Shift+S", QUICKHELP_ACTION_FILE_SAVE_AS);
		menuFile.root->Append(menuSaveAs);

		auto& menuSaveCopy = menuFile.members.menuSaveCopy;
		menuSaveCopy = new wxMenuItem(menuFile.root, wxID_ANY, "Save Co&py...", QUICKHELP_ACTION_FILE_SAVE_COPY);
		menuFile.root->Append(menuSaveCopy);

		auto& menuSaveAll = menuFile.members.menuSaveAll;
		menuSaveAll = new wxMenuItem(menuFile.root, wxID_ANY, "Sa&ve All\tCtrl+Shift+Alt+S", QUICKHELP_ACTION_FILE_SAVE_ALL);
		menuFile.root->Append(menuSaveAll);

		menuFile.root->AppendSeparator();

		auto& menuSaveTemplate = menuFile.members.menuSaveTemplate;
		menuSaveTemplate = new wxMenuItem(menuFile.root, wxID_ANY, "Save &Template", QUICKHELP_ACTION_FILE_SAVE_TEMPLATE);
		menuFile.root->Append(menuSaveTemplate);

		menuFile.root->AppendSeparator();

		auto& menuExport = menuFile.members.menuExport;
		menuExport = new wxMenuItem(menuFile.root, wxID_ANY, "&Export\tCtrl+E", QUICKHELP_ACTION_FILE_EXPORT);
		menuFile.root->Append(menuExport);

		auto& menuExportAs = menuFile.members.menuExportAs;
		menuExportAs = new wxMenuItem(menuFile.root, wxID_ANY, "Ex&port As...\tCtrl+Shift+E", QUICKHELP_ACTION_FILE_EXPORT_AS);
		menuFile.root->Append(menuExportAs);

		menuFile.root->AppendSeparator();

		auto& menuClose = menuFile.members.menuClose;
		menuClose = new wxMenuItem(menuFile.root, wxID_ANY, "&Close\tCtrl+F4", QUICKHELP_ACTION_FILE_CLOSE);
		menuFile.root->Append(menuClose);

		auto& menuCloseAll = menuFile.members.menuCloseAll;
		menuCloseAll = new wxMenuItem(menuFile.root, wxID_ANY, "Close A&ll\tCtrl+Shift+F4", QUICKHELP_ACTION_FILE_CLOSE_ALL);
		menuFile.root->Append(menuCloseAll);

		menuFile.root->AppendSeparator();

		auto& menuExit = menuFile.members.menuQuit;
		menuExit = new wxMenuItem(menuFile.root, wxID_ANY, "&Quit\tAlt+F4", QUICKHELP_ACTION_FILE_QUIT);
		menuFile.root->Append(menuExit);
		Bind(wxEVT_MENU, &FrmMain::OnMenuFileQuit, this, menuExit->GetId());
	}

	// -- Edit --
	auto& menuEdit = menuBar.menuEdit;
	menuBar.root->Append((menuEdit.root = new wxMenu()), "&Edit");
	{
	}

	// -- View --
	auto& menuView = menuBar.menuView;
	menuBar.root->Append((menuEdit.root = new wxMenu()), "&View");
	{
	}

	// -- Map --
	auto& menuMap = menuBar.menuMap;
	menuBar.root->Append((menuMap.root = new wxMenu()), "&Map");
	{
	}

	// -- Layer --
	auto& menuLayer = menuBar.menuLayer;
	menuBar.root->Append((menuLayer.root = new wxMenu()), "&Layer");
	{
	}

	// -- Tools --
	auto& menuTools = menuBar.menuTools;
	menuBar.root->Append((menuTools.root = new wxMenu()), "&Tools");
	{
	}

	// -- Help --
	auto& menuHelp = menuBar.menuHelp;
	menuBar.root->Append((menuHelp.root = new wxMenu()), "&Help");
	{
		auto& menuUserManual = menuHelp.members.menuUserManual;
		menuUserManual = new wxMenuItem(menuHelp.root, wxID_ANY, "User &Manual\tF1", QUICKHELP_ACTION_HELP_USER_MANUAL);
		menuHelp.root->Append(menuUserManual);
		Bind(wxEVT_MENU, &FrmMain::OnMenuHelpUserManual, this, menuUserManual->GetId());

		auto& menuCheckForUpdates = menuHelp.members.menuCheckForUpdates;
		menuCheckForUpdates = new wxMenuItem(menuHelp.root, wxID_ANY, "Check for &Updates", QUICKHELP_ACTION_HELP_CHECK_FOR_UPDATES);
		menuHelp.root->Append(menuCheckForUpdates);
		Bind(wxEVT_MENU, &FrmMain::OnMenuHelpCheckForUpdates, this, menuCheckForUpdates->GetId());

		menuHelp.root->AppendSeparator();

		auto& menuAbout = menuHelp.members.menuAbout;
		menuAbout = new wxMenuItem(menuHelp.root, wxID_ANY, "&About", QUICKHELP_ACTION_HELP_ABOUT);
		menuHelp.root->Append(menuAbout);
		Bind(wxEVT_MENU, &FrmMain::OnMenuHelpAbout, this, menuAbout->GetId());
	}
}

void kiwi::FrmMain::InitializeStatusBar()
{
	statusBar = new FrmMain::StatusBar(this);
	SetStatusBar(statusBar);
	PositionStatusBar();
}

kiwi::FrmMain::FrmMain(Application* application)
: wxFrame(nullptr, wxID_ANY, MAIN_WINDOW_TITLE), application(application)
{
	// frame setup
	SetMinSize(FromDIP(wxSize(200, 200))); // set minimum frame size

	// set window icon
#ifdef KIWI_SYSTEM_WINDOWS
	SetIcon(wxIcon("kiwi", wxBITMAP_TYPE_ICO_RESOURCE, 16, 16));
#else
	SetIcon(wxIcon(kiwi_xpm));
#endif

	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));

	// initialize components
	InitializeGlobalMenu();
	InitializeStatusBar();

	// bind window events
	Bind(wxEVT_MOVE, &FrmMain::OnWindowMove, this);
	Bind(wxEVT_SIZE, &FrmMain::OnWindowSize, this);
	Bind(wxEVT_CLOSE_WINDOW, &FrmMain::OnWindowClose, this);
}