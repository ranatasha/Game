#include "Zombie.hpp"
#include "../Player.hpp"  
	
Zombie::Zombie(int x, int y, int health, int damage){
    this->setX(x);
    this->setY(y);
    this->setHealth(health);
    this->setDamage(damage);
    this->setType(ZOMBIE);
}

void Zombie::move(Map* map, int x, int y){
    static int direction = 1;
    int posX = this->getX(), posY = this->getY();
    if(posY>0 && posY<map->getHeight()-1){
        if(posY==1)
            direction = 1;
        if(posY==map->getHeight()-2)
            direction = -1;
        x=posX;
        y=posY+direction; 
        if(map->getFieldPtr()[y][x].getState() != IMPASSABLE){
            if(map->getFieldPtr()[y][x].hasEntity() == false){
                map->getFieldPtr()[posY][posX].setEntity(nullptr);
                this->setX(x);
                this->setY(y);
                map->getFieldPtr()[y][x].setEntity(this);
            }
            else{
                Entity* object = map->getFieldPtr()[y][x].getEntity();
                Player* player = dynamic_cast<Player*>(object);
                if(player){
                    this->interact(*object);
                    object->CreateMessage("[PLAYER] Oh, Zombie hit me!\n");
                }
                else{ //встретился либо еще один враг, либо предмет - просто меняем на противоположное направление, след ход будет в обратном направлении
                    direction *= -1;
                }
            }
        }
        else
            direction *= -1;
    }
}