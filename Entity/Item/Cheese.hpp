#pragma once
#include "Item.hpp"
class Cheese: public Item
{
	public:
		Cheese(int posX, int posY, int value=10);
		void interact(Entity& entity) override;
};