#pragma once

#include "Creator.hpp"
#include "../Entity/Character/Player.hpp" 
#include "../Factory/CharacterFactory/CatFactory.hpp"
#include "../Factory/CharacterFactory/OwlFactory.hpp"
#include "../Factory/CharacterFactory/ZombieFactory.hpp"
#include "../Factory/ItemFactory/CheeseFactory.hpp"
#include "../Factory/ItemFactory/SwordFactory.hpp"
#include "../Factory/ItemFactory/KeyFactory.hpp"
#include <list>
	 
class TypeCreator1: public Creator {
	private:
		Character* player;
		std::list<Character*> enemies;
		std::list<Item*> items;
		Map* map;

	public:
		TypeCreator1(Map* map);
		void ResetEnemies() override;
		void ResetItems() override;
		void CreatePlayer() override;
		void CreateEnemies(int cat, int owl, int zombie) override;
		void CreateItems(int cheese, int sword, int key) override;

		Character* getPlayer();
		std::list<Character*> getEnemies();
		std::list<Item*> getItems();
		~TypeCreator1();

};
