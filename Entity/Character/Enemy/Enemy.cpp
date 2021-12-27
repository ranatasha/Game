#include "Enemy.hpp"  
#include "../Player.hpp"
#include <iostream>	
void Enemy::interact(Entity& entity){
    Character& player = dynamic_cast<Character&>(entity);
    player.setHealth(player.getHealth() - this->getDamage());
    //player.CreateMessage("Player: Enemy hit me!\n");
}