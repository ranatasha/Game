#pragma once
#include "../Entity.h"
#include "../../Map/Map.h"

enum ItemTypes{CHEESE, KEY, SWORD};

class Item: public Entity  
{
	private:
		int posX;
		int posY;
		int value;
		ItemTypes type;

	public:
		int getValue(){return value;}
		void setValue(int value){this->value=value;}
		int getX(){return posX;}
		int getY(){return posY;}
		void setX(int x){posX=x;}
		void setY(int y){posY=y;}
		ItemTypes getType(){return type;}
		void setType(ItemTypes type){this->type=type;}

};