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
///  config.h
///  ---
///  Config header.
///
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef KIWI_CONFIG_H_
#define KIWI_CONFIG_H_

#include "../thirdparty/mINI/ini.h"

namespace kiwi
{
	class Config
	{
	public:
		using T_IntPair = std::pair<int64_t, int64_t>;
		using T_UnsignedIntPair = std::pair<uint64_t, uint64_t>;

	private:
		// configuration data store
		mINI::INIStructure data;

		/**
		 * Load the default configuration data. Only implemented as a fallback
		 * for the most important initialization values in the odd case that
		 * the generated file cannot be read back for any reason - should not
		 * occur in practice.
		 */
		void LoadDefaults();

	public:
		/**
		 * Retreive a boolean value from the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 * 
		 * @return Value from the data store.
		 */
		bool GetBool(std::string const& category, std::string const& key) const;

		/**
		 * Save a boolean value in the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 * @param value Value to store.
		 */
		void SetBool(std::string const& category, std::string const& key, bool value);

		/**
		 * Retreive a string value from the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 *
		 * @return Value from the data store.
		 */
		std::string GetString(std::string const& category, std::string const& key) const;

		/**
		 * Save a string value in the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 * @param value Value to store.
		 */
		void SetString(std::string const& category, std::string const& key, std::string value);

		/**
		 * Retreive an integer value from the data store.
		 *
		 * @param category Data category.
		 * @param key Data key.
		 *
		 * @return Value from the data store.
		 */
		int64_t GetInt(std::string const& category, std::string const& key) const;

		/**
		 * Save an integer value in the data store.
		 *
		 * @param category Data category.
		 * @param key Data key.
		 * @param value Value to store.
		 */
		void SetInt(std::string const& category, std::string const& key, int64_t value);

		/**
		 * Retreive an unsigned integer value from the data store.
		 *
		 * @param category Data category.
		 * @param key Data key.
		 *
		 * @return Value from the data store.
		 */
		uint64_t GetUnsignedInt(std::string const& category, std::string const& key) const;

		/**
		 * Save an unsigned integer value in the data store.
		 *
		 * @param category Data category.
		 * @param key Data key.
		 * @param value Value to store.
		 */
		void SetUnsignedInt(std::string const& category, std::string const& key, uint64_t value);

		/**
		 * Retreive an integer pair from the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 *
		 * @return Value from the data store.
		 */
		T_IntPair GetIntPair(std::string const& category, std::string const& key) const;

		/**
		 * Save an integer pair in the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 * @param value Value to store.
		 */
		void SetIntPair(std::string const& category, std::string const& key, T_IntPair value);

		/**
		 * Retreive an unsigned integer pair value from the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 *
		 * @return Value from the data store.
		 */
		T_UnsignedIntPair GetUnsignedIntPair(std::string const& category, std::string const& key) const;

		/**
		 * Save an unsigned integer pair in the data store.
		 * 
		 * @param category Data category.
		 * @param key Data key.
		 * @param value Value to store.
		 */
		void SetUnsignedIntPair(std::string const& category, std::string const& key, T_UnsignedIntPair value);

		/**
		 * Read the data store from the configuration file.
		 *
		 * If the file doesn't exist, a default file will be created. If the
		 * file cannot be read, use default values.
		 * 
		 * @param [out] firstRun Gets set to true if the configuration file is
		 *   not found (assuming first run).
		 */
		void Read(bool& firstRun);

		/**
		 * Write the data store to the configuration file.
		 */
		void Write();
	};
}

#endif // KIWI_CONFIG_H
