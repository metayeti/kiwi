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
///  abstract_layer.h
///  ---
///  Abstract layer header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_ABSTRACT_LAYER_H_
#define KIWI_ABSTRACT_LAYER_H_

namespace kiwi
{
	class AbstractLayer
	{
	protected:
		// layer name (limited in length by LAYER_NAME_MAX_LENGTH)
		std::string name;

	public:
		AbstractLayer();
		virtual ~AbstractLayer();

		////////////////////////////////////////////////////////////////////////
		//
		//  Layer management
		//
		////////////////////////////////////////////////////////////////////////

		/**
		 * Retreive layer name.
		 * 
		 * @return Layer name.
		 */
		std::string const& GetName() const;

		/**
		 * Set layer name.
		 * 
		 * @param name New layer name.
		 */
		void SetName(std::string name);

		////////////////////////////////////////////////////////////////////////
		//
		//  Serialization
		//
		////////////////////////////////////////////////////////////////////////

		virtual void SerializeBytes(void* bytes) = 0;
	};
}

#endif // KIWI_ABSTRACT_LAYER_H_
