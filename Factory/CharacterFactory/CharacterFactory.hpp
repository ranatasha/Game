#pragma once
#include "../../Entity/Character/Character.hpp"
#include <list>
class CharacterFactory  
{
	public:
		virtual ~CharacterFactory() = default;
		virtual std::list<Character*> createCharacter(Map* map, int counter=1) = 0;

};