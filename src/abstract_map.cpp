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
///  abstract_map.cpp
///  ---
///  Abstract map implementation.
///
////////////////////////////////////////////////////////////////////////////////

#include "abstract_map.h"

kiwi::AbstractMap::AbstractMap()
{
}

kiwi::AbstractMap::~AbstractMap()
{
}

std::string const& kiwi::AbstractMap::GetName() const
{
	return name;
}

void kiwi::AbstractMap::SetName(std::string name)
{
	this->name = name;
}

void kiwi::AbstractMap::RaiseLayer(size_t index)
{
}

void kiwi::AbstractMap::LowerLayer(size_t index)
{
}

void kiwi::AbstractMap::MoveLayer(size_t index, size_t indexTo)
{
}

void kiwi::AbstractMap::SwapLayers(size_t indexFirst, size_t indexSecond)
{
}