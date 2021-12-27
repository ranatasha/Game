#include "Player.hpp"  
#include "Enemy/Enemy.hpp"
#include "../Item/Item.hpp"	

Player::Player(int x, int y, int health, int damage, bool key){
    this->setX(x);
    this->setY(y);
    this->setHealth(health);
    this->setDamage(damage);
    this->setKey(key);
    this->setType(PLAYER);
}

void Player::interact(Entity& entity){
    Character& enemy = dynamic_cast<Character&>(entity);
    enemy.setHealth(enemy.getHealth() - this->getDamage());
    if(enemy.getHealth() > 0){
        enemy.CreateMessage("[ENEMY_FIGHT] Oh, Player hit me!\n");
    }
    else
        enemy.CreateMessage("[ENEMY_KILLED] Oh, Player killed me!\n");

}

void Player::move(Map* map, int x, int y){
    this->setTakeItem(false);
    if(x>=0 && x<map->getWidth() && y>=0 && y<map->getHeight()){
        if(map->getFieldPtr()[y][x].getState() != IMPASSABLE){
            if(map->getFieldPtr()[y][x].hasEntity() == false){
                map->getFieldPtr()[this->getY()][this->getX()].setEntity(nullptr);
                this->setX(x);
                this->setY(y);
                map->getFieldPtr()[y][x].setEntity(this);
            }
            else{
                Entity* object = map->getFieldPtr()[y][x].getEntity();
                Item* item = dynamic_cast<Item*>(object);
                if(item){
                    this->setTakeItem(true);
                    object->interact(*this);
                    map->getFieldPtr()[y][x].setEntity(nullptr);
                    item->setX(-1);
                    item->setY(-1);
                }
                else{
                    this->interact(*object);
                    Character& enemy = dynamic_cast<Character&>(*object);
                    if(!enemy.isAlive())
                        map->getFieldPtr()[y][x].setEntity(nullptr);
                }
            }
        }
    }
}