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
///  abstract_layer.cpp
///  ---
///  Abstract layer implementation.
///
////////////////////////////////////////////////////////////////////////////////

#include <string>

#include "abstract_layer.h"

kiwi::AbstractLayer::AbstractLayer()
{
}

kiwi::AbstractLayer::~AbstractLayer()
{
}

std::string const& kiwi::AbstractLayer::GetName() const
{
	return name;
}

void kiwi::AbstractLayer::SetName(std::string name)
{
	this->name = name;
}
