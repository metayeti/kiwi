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
///  const.h
///  ---
///  Application-wide constants.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_CONST_H_
#define KIWI_CONST_H_

namespace kiwi
{
	// current kiwi version
	// == The following entry NEEDS to exist on line 29 so that "update_versions" utility can properly update it! ==
	const char* const KIWI_VERSION = "0.0.2";

	// filenames
	const char* const KIWI_INI_FILENAME = "kiwi.ini";

	// URLs
	const char* const URL_GITHUB_MANUAL = "https://github.com/metayeti/kiwi/tree/main/manual/";
	const char* const URL_GITHUB_RELEASES = "https://github.com/metayeti/kiwi/releases";

	// main window constants
	const char* const MAIN_WINDOW_TITLE = "kiwi";

	// map type
	const int MAP_TYPE_ORTHOGONAL = 0;
	const int MAP_TYPE_ISOMETRIC = 1;
	const int MAP_TYPE_HEXAGONAL = 2;

	// map constraints
	const size_t MAP_NAME_MAX_LENGTH = 100;
	const size_t MAP_MIN_WIDTH = 1;
	const size_t MAP_MIN_HEIGHT = 1;
	const size_t MAP_MAX_WIDTH = 1000;
	const size_t MAP_MAX_HEIGHT = 1000;
	const size_t CELL_MIN_WIDTH = 1;
	const size_t CELL_MIN_HEIGHT = 1;
	const size_t CELL_MAX_WIDTH = 1000;
	const size_t CELL_MAX_HEIGHT = 1000;

	// layer constraints
	const size_t LAYER_NAME_MAX_LENGTH = 100;

	// serialization constants
	const std::string KIWFILE_BINARY_BGN_POINT = "kw>";
	const std::string KIWFILE_BINARY_END_POINT = "<wk";
	const std::string MAPFILE_BINARY_BGN_POINT = "mp>";
	const std::string MAPFILE_BINARY_END_POINT = "<pm";
	
	// GUI constants
	const int GUI_DEFAULT_BORDER_SIZE = 10;
	const int GUI_DOUBLE_BORDER_SIZE = 20;
	const int GUI_HALF_BORDER_SIZE = 5;
	const int GUI_DEFAULT_GRID_HORIZONTAL_GAP = 25;
	/////const int GUI_GROUP_BOX_VERTICAL_SPACING = 24; // might need later
	const int GUI_DEFAULT_BUTTON_WIDTH = 110;
	const int GUI_DEFAULT_BUTTON_HEIGHT = 30;
	
	// help strings
	const char* const QUICKHELP_ACTION_FILE_NEW = "Create a new map";
	const char* const QUICKHELP_ACTION_FILE_NEW_FROM_TEMPLATE = "Create a map from existing template";
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

	const char* const QUICKHELP_ACTION_LAYER_CREATE_NEW = "Create a new layer";
	const char* const QUICKHELP_ACTION_LAYER_DUPLICATE = "Duplicate this layer";
	const char* const QUICKHELP_ACTION_LAYER_MERGE = "Merge this layer with another";
	const char* const QUICKHELP_ACTION_LAYER_DELETE = "Delete this layer";
	const char* const QUICKHELP_ACTION_LAYER_RAISE = "Raise this layer to one level above current";
	const char* const QUICKHELP_ACTION_LAYER_LOWER = "Lower this layer to one level below current";
	const char* const QUICKHELP_ACTION_LAYER_LAYER_PROPERTIES = "Open the layer properties dialog";

	const char* const QUICKHELP_ACTION_TOOLS_SETTINGS = "Open the program settings dialog";

	const char* const QUICKHELP_ACTION_HELP_USER_MANUAL = "Open online help";
	const char* const QUICKHELP_ACTION_HELP_CHECK_FOR_UPDATES = "Check online repository for updates";
	const char* const QUICKHELP_ACTION_HELP_ABOUT = "Show the about dialog";
}

#endif // KIWI_CONST_H_
