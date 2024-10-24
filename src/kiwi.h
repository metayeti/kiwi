////////////////////////////////////////////////////////////////////////////////
///   __    __         __ 
///  |  | _|__|_  _  _|__|   Kit for Interactive World Integration
///  |  |/ /  \ \/ \/ /  |   A 2D game map editor
///  |    <|  |\  _  /|  |   ( version 0.0.3 dev )
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
///  kiwi.h
///  ---
///  Main headerfile for kiwi. Defines system-level globals.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_H_
#define KIWI_H_

#if defined(_WIN32) || defined(__CYGWIN__)
	#define KIWI_SYSTEM_WINDOWS
#elif defined(__linux__)
	#define KIWI_SYSTEM_LINUX
#elif defined(__APPLE__)
	#define KIWI_SYSTEM_MACOS
#endif

#if defined(DEBUG) || defined(_DEBUG)
	#define KIWI_DEBUG_BUILD
#endif

#if defined(KIWI_SYSTEM_WINDOWS)
	// disable annoying warnings on VS
	#pragma warning(disable: 4996)
	#pragma warning(disable: 26812)
	#pragma warning(disable: 6011)
	#pragma warning(disable: 26812)
	#pragma warning(disable: 26451)
	#pragma warning(disable: 26495)
	#pragma warning(disable: 26439)
#endif

//#include "wx/wxprec.h"
//#ifndef WX_PRECOMP
	#include "wx/wx.h"
	#include "wx/spinctrl.h"
	#include "wx/aui/aui.h"
//#endif

// ~~~ VLD ~~~ uncomment to enable leak detection
//#include "vld.h"

#endif // KIWI_H_
