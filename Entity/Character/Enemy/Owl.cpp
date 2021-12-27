#include "Owl.hpp" 
#include "../Player.hpp" 
	
Owl::Owl(int x, int y, int health, int damage){
    this->setX(x);
    this->setY(y);
    this->setHealth(health);
    this->setDamage(damage);
    this->setType(OWL);
}

void Owl::move(Map* map, int x, int y){
    static int direction = 2;
    int posX = this->getX(), posY = this->getY();
    if(posX>0 && posX<map->getWidth()-1){
        if(posX==1)
            direction = 2;
        if(posX==map->getWidth()-2)
            direction = -2;
        x=posX+direction;
        y=posY; 
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
                    object->CreateMessage("[PLAYER] Oh, Owl hit me!\n");
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

