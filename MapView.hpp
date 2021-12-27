#pragma once
#include <SFML/Graphics.hpp>
#include "Entity/Entity.h"
#include "Entity/Character/Player.hpp" 
#include "Entity/Character/Enemy/Cat.hpp"
#include "Entity/Character/Enemy/Owl.hpp"
#include "Entity/Character/Enemy/Zombie.hpp"
#include "Entity/Item/Cheese.hpp"
#include "Entity/Item/Sword.hpp"
#include "Entity/Item/Key.hpp"
#include "Map/Map.h"
using namespace sf;
class MapView  
{
	private:
		Map* map;
		RenderWindow* window;

	public:
		MapView(Map* map, RenderWindow* window);
		void printMap();

};