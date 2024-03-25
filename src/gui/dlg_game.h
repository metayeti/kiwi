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
///  dlg_game.h
///  ---
///  Game dialog header.
///
////////////////////////////////////////////////////////////////////////////////

#ifndef KIWI_DLG_GAME_H_
#define KIWI_DLG_GAME_H_

namespace kiwi
{

	enum class T_ItemType : char
	{
		WEAPON_1H,
		WEAPON_2H,
		SHIELD,
		HELMET,
		CHEST,
		GLOVES,
		PANTS,
		BOOTS,
		KEY,
		SCROLL,
		BOOK,
		TREASURE,
		GARBAGE
	};

	enum class T_SpellType : char
	{
		FIRE_SPELL,
		WATER_SPELL,
		AIR_SPELL,
		EARTH_SPELL,
		ILLUSION_SPELL,
		VOID_SPELL
	};

	class Item
	{
	private:


	public:
		Item();
	};

	class Spell
	{
	};

	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
	};

	class Player : public Entity
	{
	private:
		using T_Inventory = std::vector<int>;
		using T_SpellBook = std::vector<int>;
		
		T_Inventory inventory;
		T_SpellBook spellBook;
		unsigned int gold;

		struct Equipped
		{
			Item* hand1;
			Item* hand2;
			Item* helmet;
			Item* chest;
			Item* gloves;
			Item* pants;
			Item* boots;
		} equipped;

	public:
		Player();
		~Player();
	};

	class Map
	{
		Map();
	public:
		~Map();

		Map* CreateMapFromBlob();
		Map* CreateMapAtRandom();
	};

	class World
	{
	private:
		using T_MapType = std::unique_ptr<int>;
		using T_ItemDB = std::vector<Item>;

		T_MapType mapOverworld;
		T_MapType mapCatacombs;
		T_MapType mapIcaria;
		T_MapType mapUnderworld;
		T_MapType mapMorlona;

		void CreateItemDB();
		void CreateEntityDB();

	public:
		World();
		~World();
	};

	class DlgGame : public wxDialog
	{
	private:



		/**
		 * Creates a brand new game. Resets the world and everything in it.
		 */
		void CreateNewGame();

	public:
		DlgGame(wxWindow* parent);
	};
}

#endif // KIWI_DLG_GAME_H_