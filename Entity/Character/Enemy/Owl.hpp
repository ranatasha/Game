#pragma once
#include "Enemy.hpp"
class Owl: public Enemy  
{
	public:
		Owl(int x, int y, int health=10, int damage=5);
		void move(Map* map, int x=0, int y=0) override;

		friend std::ostream& operator<<(std::ostream& out, Owl* obj){
    		out<<"Owl --> Health: "<< obj->getHealth()<<"; Damage: " << obj->getDamage()<<"\n\n";
    		return out;
		}
};