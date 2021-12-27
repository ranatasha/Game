#pragma once
#include "Item.hpp"
class Sword: public Item
{
	public:
		Sword(int x, int y, int value=2);
		void interact(Entity& entity) override;
};