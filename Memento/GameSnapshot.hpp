#pragma once
#include "Memento.hpp"
#include "../Entity/Entity.h"
#include "../Entity/Character/Character.hpp"
#include "../Entity/Character/Player.hpp"
#include "../Entity/Character/Enemy/Cat.hpp"
#include "../Entity/Character/Enemy/Owl.hpp"
#include "../Entity/Character/Enemy/Zombie.hpp"
#include "../Entity/Item/Item.hpp"
#include "../Entity/Item/Cheese.hpp"
#include "../Entity/Item/Key.hpp"
#include "../Entity/Item/Sword.hpp"

#include <string>
#include <fstream>

class GameSnapshot: public Memento  
{
	private:
		std::string state;
		GameState* loadedState;

	public:
		GameSnapshot() = delete;
		GameSnapshot(Map* map, Character* player, int n_enemies, std::list<Character*> enemies, int n_items, std::list<Item*> items);

		void SaveGame() override;
		void RestoreState(GameState* origState) override;
		void changeState(GameState* origState);

};