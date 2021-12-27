#pragma once

#include "../Map/Map.h"
#include "../Entity/Character/Character.hpp"
#include "../Entity/Item/Item.hpp"
#include <list>

typedef struct GameState{
	Map* new_map;
	Character* new_player;
	int new_n_enem;
	std::list<Character*> new_enemies;
	int new_n_items;
	std::list<Item*> new_items;
} GameState;

class Memento  
{
	public:

		virtual void SaveGame() = 0;
		virtual void RestoreState(GameState* origState) = 0;
		virtual ~Memento() = default;

};