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
///  application.h
///  ---
///  Application header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_APPLICATION_H_
#define KIWI_APPLICATION_H_

namespace kiwi
{
	class Application : public wxApp
	{
	private:
		Config config;
	public:
		/**
		 * Initialize the application and show the main window.
		 * Also loads the application configuration.
		 */
		virtual bool OnInit() override;

		/**
		 * Retreive (preloaded) application configuration.
		 */
		Config* GetConfig();
	};
}

#endif // KIWI_APPLICATION_H_
