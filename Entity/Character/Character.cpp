#include "Character.hpp"  
	
bool Character::isAlive(){
    if(health > 0)
        return true;
    return false;
}