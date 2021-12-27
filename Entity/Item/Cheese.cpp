#include "Cheese.hpp"  
#include "../Character/Player.hpp"
Cheese::Cheese(int x, int y, int value)
{
	this->setX(x);
    this->setY(y);
    this->setValue(value);
    this->setType(CHEESE);
}

void Cheese::interact(Entity& entity){
    Character& player = dynamic_cast<Character&>(entity);
    player.setHealth(player.getHealth()+this->getValue());
    player.CreateMessage("[PLAYER_HEALTH] I took cheese! My health is grew up!\n");
    //player.Notify();
}