#include "Sword.hpp"   
#include "../Character/Player.hpp"
Sword::Sword(int x, int y,int value)
{
	this->setX(x);
    this->setY(y);
    this->setValue(value);
    this->setType(SWORD);
}

void Sword::interact(Entity& entity){
    Character& player = dynamic_cast<Character&>(entity);
    player.setDamage(player.getDamage()+this->getValue());
    player.CreateMessage("[PLAYER_DAMAGE] I took a sword! My damage is grew up!\n");
    //player.Notify();
}