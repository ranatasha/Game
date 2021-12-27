#pragma once
#include "CharacterFactory.hpp"
#include "../../Entity/Character/Enemy/Cat.hpp"
class CatFactory: public CharacterFactory  
{
	public:
		std::list<Character*> createCharacter(Map* map, int counter=1) override{
			std::list<Character*> result;
			srand(time(NULL));
			int x,y;
			for(int i=0;i<counter;i++){
				do{
					x=1 + rand() % (map->getWidth()-1 - 1);
					y=1 + rand() % (map->getHeight()-1 -1);
				}
				while(map->getFieldPtr()[y][x].getState() != PASSABLE || map->getFieldPtr()[y][x].hasEntity());
				Character* cat = new Cat(x,y);
				map->getFieldPtr()[y][x].setEntity(cat);
				result.push_back(cat);
			}
			return result;
		}
};