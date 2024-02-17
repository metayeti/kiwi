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
///  util.h
///  ---
///  Utility functions header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_UTIL_H_
#define KIWI_UTIL_H_

namespace kiwi::Util
{
	/**
	 * Split a string.
	 * 
	 * @param str Input string.
	 * @param delimited Split delimiter.
	 * 
	 * @return The split result.
	 */
	std::vector<std::string> SplitStr(std::string str, std::string const& delimiter = " ");

	/**
	 * Make a string lowercase.
	 * 
	 * @param [out] str String to manipulate.
	 */
	void StrToLower(std::string& str);

	/**
	 * Make a string uppercase.
	 * 
	 * @param [out] str String to manipulate.
	 */
	void StrToUpper(std::string& str);

	/**
	 * Trim whitespace from right-hand side of a string.
	 * 
	 * @param [out] str String to manipulate.
	 */
	void TrimStrR(std::string& str);

	/**
	 * Trim whitespace from left-hand side of a string.
	 * 
	 * @param [out] str String to manipulate.
	 */
	void TrimStrL(std::string& str);

	/**
	 * Trim whitespace from both sides of a string.
	 *
	 * @param [out] str String to manipulate.
	 */
	void TrimStr(std::string& str);

	/**
	 * Check whether or not the specified filename exists.
	 * 
	 * @param filename Input filename.
	 * 
	 * @return Returns if filename exists.
	 */
	bool FileExists(const std::string& filename);

	/**
	 * Splits an XPM resource into several bitmaps of varying sizes.
	 *
	 * @return A bitmap bundle.
	 */
	wxBitmapBundle XPMToBitmapBundle(const char* const* data, int baseWidth, int baseHeight, wxImageResizeQuality quality = wxIMAGE_QUALITY_NORMAL);
}

#endif // KIWI_UTIL_H_