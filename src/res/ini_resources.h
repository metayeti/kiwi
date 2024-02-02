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
///  ini_resources.h
///  ---
///  Hardcoded INI resources.
///
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_INI_RESOURCES_H_
#define MW_INI_RESOURCES_H_

namespace kiwi
{
	// == The following entry NEEDS to exist on line 30 so that "inject_config" utility can properly update it! ==
	const char* const INI_CONFIG = "; ------------------ ;\n; kiwi configuration ;\n; ------------------ ;\n\n; -- startup settings --\n[startup]\n; center window on launch (yes / no)\ncenter = yes\n; window position on launch ({x}, {y})\nposition = 0, 0\n; window size on launch ({width}, {height})\nsize = 800, 600\n; maximized state on launch (yes / no)\nmaximize = no\n\n; -- default mapfile --\n[default_map]\n; default grid size in pixels ({width}, {height})\ngrid_size = 50, 50\n; default map size in cells ({width}, {height})\nmap_size = 100, 100\n; default map type (ort / iso / hex)\nmap_type = orthogonal\n; default map staggering (yes / no)\nmap_stagger = no\n\n; -- recent-files list --\n[recent]\n";
}

#endif // MW_INI_RESOURCES_H_