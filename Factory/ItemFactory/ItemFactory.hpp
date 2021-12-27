#pragma once
#include "../../Entity/Item/Item.hpp"
#include <list>
class ItemFactory  
{
	public:
		virtual ~ItemFactory() = default;
		virtual std::list<Item*> createItem(Map* map, int counter=1) = 0;

};