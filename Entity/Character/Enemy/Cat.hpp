#pragma once
#include "Enemy.hpp"
class Cat: public Enemy  
{
	public:
		Cat(int x, int y, int health=6, int damage=4);
		void move(Map* map, int x=0, int y=0) override;

		friend std::ostream& operator<<(std::ostream& out, Cat* obj){
    		out<<"Cat --> Health: "<< obj->getHealth()<<"; Damage: " << obj->getDamage()<<"\n\n";
    		return out;
		}
};