#pragma once
#include "ItemFactory.hpp"
#include "../../Entity/Item/Key.hpp"
class KeyFactory: public ItemFactory  
{
	public:
		std::list<Item*> createItem(Map* map, int counter=1) override{
			std::list<Item*> result;
			srand(time(NULL));
			int x,y;
			for(int i=0;i<counter;i++){
				do{
					x=1 + rand() % (map->getWidth()-1 - 1);
					y=1 + rand() % (map->getHeight()-1 -1);
				}
				while(map->getFieldPtr()[y][x].getState() != PASSABLE || map->getFieldPtr()[y][x].hasEntity());
				Item* key = new Key(x,y);
				map->getFieldPtr()[y][x].setEntity(key);
				result.push_back(key);
			}
			return result;
		}
};