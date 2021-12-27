#pragma once
#include "Command.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Entity/Character/Player.hpp"
#include "../Entity/Character/Character.hpp"
#include "../Map/Map.h"
#include <list>

enum Directions{NO, UP, DOWN, LEFT, RIGHT, SAVE, LOAD};
	
class ReadKey: public Command  
{
	private:
		sf::Event* event;
		bool pressed;
		Directions direction;

		// std::function<void(int x, int y)> move_func;
		// std::function<int()> accessX;
		// std::function<int()> accessY;

	public:
		//ReadKey(sf::Event* event, std::function<int()> accessX, std::function<int()> accessY, std::function<void(int x, int y)> move_func);
		void execute() override;
		void setDirection(Directions direction){this->direction = direction;};
		void setPressed(bool pressed){this->pressed = pressed;}
		void setEvent(sf::Event* event){this->event=event;}
		Directions getDirection(){return this->direction;}
		// int getX();
		// int getY();
		//std::function<void(Map* map, Player* player, int x, int y, std::list<Character*> enemies)> getFunc(){return this->move_func;}

};