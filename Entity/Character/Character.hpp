#pragma once
#include "../Entity.h"	
#include "../../Map/Map.h"
enum CharTypes{PLAYER,CAT,OWL,ZOMBIE};
class Character: public Entity  
{
	private:
		int posX;
		int posY;
		int health;
		int damage;
		CharTypes type;
	public:
		int getX(){return posX;}
		int getY(){return posY;}
		void setX(int x){posX = x;}
		void setY(int y){posY = y;}
		int getHealth(){return health;}
		void setHealth(int value){health = value;}
		int getDamage(){return damage;}
		void setDamage(int value){damage = value;}
		bool isAlive();
		CharTypes getType(){return type;}
		void setType(CharTypes type){this->type=type;}

		virtual void move(Map* map, int x=0, int y=0) = 0;

		virtual ~Character() = default;

};