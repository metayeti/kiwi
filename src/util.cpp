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
///  util.cpp
///  ---
///  Utility functions implementation.
///
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

#include "kiwi.h"
#include "util.h"

std::vector<std::string> kiwi::Util::SplitStr(std::string str, std::string const& delimiter)
{
	//
	// Adopted from https://stackoverflow.com/a/14266139
	//
	std::vector<std::string> result;
	size_t pos = 0;
	while ((pos = str.find(delimiter)) != std::string::npos)
	{
		result.push_back(str.substr(0, pos));
		str.erase(0, pos + delimiter.length());
	}
	result.push_back(str);
	return result;
}

void kiwi::Util::StrToLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
		return std::tolower(c);
	});
}

void kiwi::Util::StrToUpper(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
		return std::toupper(c);
	});
}

void kiwi::Util::TrimStrR(std::string& str)
{
	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), str.end());
}

void kiwi::Util::TrimStrL(std::string& str)
{
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char c) { return !std::isspace(c); }));
}

void kiwi::Util::TrimStr(std::string& str)
{
	TrimStrR(str);
	TrimStrL(str);
}

bool kiwi::Util::FileExists(const std::string& filename)
{
	std::ifstream in(filename);
	return in.good();
}

wxBitmapBundle kiwi::Util::XPMToBitmapBundle(const char* const* data, int baseWidth, int baseHeight, wxImageResizeQuality quality)
{
	wxImage image(data);
	wxVector<wxBitmap> bitmaps;
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth, baseHeight, quality))); // 100%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.25, baseHeight * 1.25, quality))); // 125%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.5, baseHeight * 1.5, quality))); // 150%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.75, baseHeight * 1.75, quality))); // 175%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 2, baseHeight * 2, quality))); // 200%
	return wxBitmapBundle::FromBitmaps(bitmaps);
}