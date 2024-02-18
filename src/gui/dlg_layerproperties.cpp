/////////////////////////////////////////////////////////////////////////////
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
///  dlg_layerproperties.cpp
///  ---
///  Layer properties dialog implementation.
///
////////////////////////////////////////////////////////////////////////////////

#include "../kiwi.h"
#include "dlg_layerproperties.h"

kiwi::DlgLayerProperties::DlgLayerProperties(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "Layer Properties", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
}