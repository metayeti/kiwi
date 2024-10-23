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
///  orthogonal_map.h
///  ---
///  Orthogonal map header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_ORTHOGONAL_MAP_H_
#define KIWI_ORTHOGONAL_MAP_H_

#include "abstract_map.h"

namespace kiwi
{
	class OrthogonalMap : public AbstractMap
	{
	public:
		/**
		 * OrthogonalMap constructor.
		 */
		OrthogonalMap();

		/**
		 * OrthogonalMap destructor.
		 */
		~OrthogonalMap();

		/**
		 * Resize the map.
		 *
		 * @param width New map width.
		 * @param height New map height.
		 * 
		 * @override
		 */
		void Resize(size_t width, size_t height);

		/**
		 * Serializes map data to bytes.
		 * 
		 * @param bytes Bytestream output.
		 * 
		 * @override
		 */
		virtual void SerializeBytes(void* bytes);

	};
}

#endif // KIWI_ORTHOGONAL_MAP_H_