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
///  dlg_settings.cpp
///  ---
///  Settings dialog implementation.
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_settings.h"

kiwi::DlgSettings::DlgSettings(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "Settings", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
}