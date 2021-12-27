#pragma once
#include "Character.hpp"	
#include <string.h>
class Player: public Character  
{
	private:
		bool key;
		bool take_item;

	public:
		Player(int x, int y,int health=10, int damage=4, bool key=false);

		bool hasKey(){return key;}
		void setKey(bool value){key = value;}
		void setTakeItem(bool value){take_item = value;}
		bool getTakeItem(){return take_item;}
		void interact(Entity& entity) override;
		void move(Map* map, int x=0, int y=0) override;

		friend std::ostream& operator<<(std::ostream& out, Player* obj){
    		out<<"Player --> Health: "<< obj->getHealth()<<"; Damage: " << obj->getDamage() << "; HasKey?: " << obj->hasKey()<<"\n\n";
    		return out;
		}

};