#pragma once
#include "../Character.hpp"
class Enemy: public Character  
{
	public:
		void interact(Entity& entity) override;
};