#pragma once
#include "Item.hpp"
class Key: public Item
{
	public:
		Key(int posX, int posY, int value=1);
		void interact(Entity& entity) override;
};