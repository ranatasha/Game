#pragma once
#include "Enemy.hpp"
class Zombie: public Enemy  
{
	public:
		Zombie(int x, int y, int health=12, int damage=3);
		void move(Map* map, int x=0, int y=0) override;

		friend std::ostream& operator<<(std::ostream& out, Zombie* obj){
    		out<<"Zombie --> Health: "<< obj->getHealth()<<"; Damage: " << obj->getDamage()<<"\n\n";
    		return out;
		}

};