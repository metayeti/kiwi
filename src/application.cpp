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
///  application.cpp
///
////////////////////////////////////////////////////////////////////////////////

#include "kiwi.h"
#include "config.h"
#include "application.h"
#include "gui/frm_main.h"

wxDECLARE_APP(kiwi::Application);

bool kiwi::Application::OnInit()
{
	// load the application configuration
	bool firstRun = false;
	config.Read(firstRun);
	// fetch window parameters from config
	bool center = config.GetBool("startup", "center");
	Config::T_UnsignedIntPair position = config.GetUnsignedIntPair("startup", "position");
	Config::T_UnsignedIntPair size = config.GetUnsignedIntPair("startup", "size");
	bool maximize = config.GetBool("startup", "maximize");
	// setup the main application window
	FrmMain* window = new FrmMain(this);
	if (firstRun)
	{
		// if this is our first run, treat dimensions specified in the config as DPI-dependent values
		// (this is to ensure that the first run on a high DPI display won't show a tiny window)
		window->SetSize(window->FromDIP(wxSize(size.first, size.second)));
	}
	else
	{
		// otherwise treat dimensions as normal
		window->SetSize(wxSize(size.first, size.second));
	}
	if (center || maximize)
	{
		window->CenterOnScreen();
	}
	else
	{
		window->SetPosition(wxPoint(position.first, position.second));
	}
	if (maximize)
	{
		window->Maximize();
	}
	// display the main application window
	window->Show(true);
	return true;
}

kiwi::Config* kiwi::Application::GetConfig()
{
	return &config;
}

wxIMPLEMENT_APP(kiwi::Application);
