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
///  const.h
///  ---
///  Global constants.
///
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_CONST_H_
#define KIWI_CONST_H_

namespace kiwi
{
	// current kiwi version
	// == The following entry NEEDS to exist on line 31 so that "update_versions" utility can propery update it! ==
	const char* const KIWI_VERSION = "0.0.1";

	// filenames
	const char* const FILENAME_CONFIG_INI = "kiwi.ini";

	// github URLs
	const char* const URL_GITHUB_MANUAL = "https://github.com/metayeti/kiwi/tree/main/manual/";
	const char* const URL_GITHUB_RELEASES = "https://github.com/metayeti/kiwi/releases";

	// main window
	const char* const MAIN_WINDOW_TITLE = "kiwi";

	// map constraints
	const size_t MAP_NAME_MAX_LENGTH = 100;
	const size_t MAP_MIN_W = 1;
	const size_t MAP_MIN_H = 1;
	const size_t MAP_MAX_W = 1000;
	const size_t MAP_MAX_H = 1000;

	// layer constraints
	const size_t LAYER_NAME_MAX_LENGTH = 100;

	// serialization constants
	const std::string KIWFILE_BINARY_BGN_POINT = "kiw>";
	const std::string KIWFILE_BINARY_END_POINT = "<wik";
	const std::string MAPFILE_BINARY_BGN_POINT = "map>";
	const std::string MAPFILE_BINARY_END_POINT = "<pam";
	
	// help strings
	const char* const QUICKHELP_ACTION_FILE_NEW = "Create a new map";
	const char* const QUICKHELP_ACTION_FILE_OPEN = "Open an existing map";
	const char* const QUICKHELP_ACTION_FILE_SAVE = "Save this map";
	const char* const QUICKHELP_ACTION_FILE_SAVE_AS = "Save this map as";
	const char* const QUICKHELP_ACTION_FILE_SAVE_COPY = "Save a copy of this map";
	const char* const QUICKHELP_ACTION_FILE_SAVE_ALL = "Save all open maps";
	const char* const QUICKHELP_ACTION_FILE_SAVE_TEMPLATE = "Save this map as template";
	const char* const QUICKHELP_ACTION_FILE_EXPORT = "Export this map";
	const char* const QUICKHELP_ACTION_FILE_EXPORT_AS = "Export this map as";
	const char* const QUICKHELP_ACTION_FILE_CLOSE = "Close this map";
	const char* const QUICKHELP_ACTION_FILE_CLOSE_ALL = "Close all open maps";
	const char* const QUICKHELP_ACTION_FILE_QUIT = "Quit the program";

	const char* const QUICKHELP_ACTION_EDIT_UNDO = "Undo last action";
	const char* const QUICKHELP_ACTION_EDIT_REDO = "Redo previous undo";
	const char* const QUICKHELP_ACTION_EDIT_CUT = "Cut selection";
	const char* const QUICKHELP_ACTION_EDIT_COPY = "Copy selection";
	const char* const QUICKHELP_ACTION_EDIT_PASTE = "Paste from clipboard";
	const char* const QUICKHELP_ACTION_EDIT_DELETE = "Delete selection";

	const char* const QUICKHELP_ACTION_TOOLS_SETTINGS = "Show the settigs dialog";

	const char* const QUICKHELP_ACTION_HELP_USER_MANUAL = "Open online help";
	const char* const QUICKHELP_ACTION_HELP_CHECK_FOR_UPDATES = "Check online repository for updates";
	const char* const QUICKHELP_ACTION_HELP_ABOUT = "Show the about dialog";
}

#endif // KIWI_CONST_H_