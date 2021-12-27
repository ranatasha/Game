#include "Key.hpp"  
#include "../Character/Player.hpp"
#include<iostream>
Key::Key(int x, int y, int value) 
{
	this->setX(x);
    this->setY(y);
    this->setValue(value);
    this->setType(KEY);
}

void Key::interact(Entity& entity){
    Player& player = dynamic_cast<Player&>(entity);
    player.setKey(this->getValue());
    player.CreateMessage("[PLAYER_KEY] I took a key!\n");
    //player.Notify();
}