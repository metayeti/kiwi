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
///  abstract_map.h
///  ---
///  Abstract map header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_ABSTRACT_MAP_H_
#define KIWI_ABSTRACT_MAP_H_

#include <vector>
#include <string>
#include <unordered_map>

namespace kiwi
{
	class AbstractLayer;

	class AbstractMap
	{
	public:
		using T_LayerList = std::vector<AbstractLayer*>;
		using T_PropertyMap = std::unordered_map<std::string, std::string>;

	protected:
		// map name (limited in length by MAP_NAME_MAX_LENGTH)
		std::string name;

		// map dimensions
		size_t mapWidth = 0;
		size_t mapHeight = 0;

		// base tile size
		size_t tileBaseWidth = 0;
		size_t tileBaseHeight = 0;

		// indicates whether the map is a staggered type
		bool staggered = false;

	public:
		T_LayerList layers;
		T_PropertyMap properties;

		/**
		 * AbstractMap constructor.
		 */
		AbstractMap();

		/**
		 * AbstractMap destructor.
		 */
		virtual ~AbstractMap();

		////////////////////////////////////////////////////////////////////////
		//
		//  Map management
		//
		////////////////////////////////////////////////////////////////////////

		/**
		 * Retreive layer name.
		 *
		 * @returns Layer name.
		 */
		std::string const& GetName() const;

		/**
		 * Set layer name.
		 *
		 * @param name New layer name.
		 */
		void SetName(std::string name);

		/**
		 * Resize the map.
		 *
		 * @param width New map width.
		 * @param height New map height.
		 */
		virtual void Resize(size_t width, size_t height) = 0;

		////////////////////////////////////////////////////////////////////////
		//
		//  Map-level layer management
		//
		////////////////////////////////////////////////////////////////////////

		/**
		 * Raise a layer one level up, if possible.
		 * 
		 * @param index The index of the layer to raise.
		 */
		void RaiseLayer(size_t index);

		/**
		 * Lower a layer one level down, if possible.
		 *
		 * @param index The index of the layer to lower.
		 */
		void LowerLayer(size_t index);

		/**
		 * Move a layer to specified index in-place, if possible.
		 *
		 * 
		 * @param index The index of the layer to move.
		 * @param indexTo Destination layer index.
		 */
		void MoveLayer(size_t index, size_t indexTo);

		/**
		 * Swap two layers.
		 *
		 * @param indexFirst First layer index.
		 * @param indexSecond Second layer index.
		 */
		void SwapLayers(size_t indexFirst, size_t indexSecond);

		////////////////////////////////////////////////////////////////////////
		//
		//  Serialization
		//
		////////////////////////////////////////////////////////////////////////

		virtual void SerializeBytes(void* bytes) = 0;
	};
}

#endif // KIWI_ABSTRACT_MAP_H_
