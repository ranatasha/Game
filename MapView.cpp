#include "MapView.hpp"  
	
MapView::MapView(Map* map, RenderWindow* window): map(map), window(window){}
	
void MapView::printMap(){
    Texture textures[11];
    textures[0].loadFromFile("../textures/impassable.png");
    textures[1].loadFromFile("../textures/passable.png");
    textures[2].loadFromFile("../textures/entry.png");
    textures[3].loadFromFile("../textures/exit.png");
    textures[4].loadFromFile("../textures/player.png");
    textures[5].loadFromFile("../textures/cat.png");
    textures[6].loadFromFile("../textures/owl.png");
    textures[7].loadFromFile("../textures/zombie.png");
    textures[8].loadFromFile("../textures/cheese.png");
    textures[9].loadFromFile("../textures/sword.png");
    textures[10].loadFromFile("../textures/key.png");

    Sprite sprite;
    States cellState;

    for(int i=0; i< map->getHeight();i++){
        for(int j=0;j< map->getWidth();j++){
            cellState = map->getFieldPtr()[i][j].getState();
            sprite = Sprite(textures[cellState]);
            sprite.setPosition(j * 32, i * 32);
            window->draw(sprite);

            if(map->getFieldPtr()[i][j].hasEntity()){
                Entity* object = map->getFieldPtr()[i][j].getEntity();
                int entType;
            
                Player* player = dynamic_cast<Player*>(object);
                if(player)
                    entType = 0;
                
                Cat* cat = dynamic_cast<Cat*>(object);
                if(cat)
                    entType = 1;
                
                Owl* owl = dynamic_cast<Owl*>(object);
                if(owl)
                    entType = 2;
                
                Zombie* zombie = dynamic_cast<Zombie*>(object);
                if(zombie)
                    entType = 3;

                Cheese* cheese = dynamic_cast<Cheese*>(object);
                if(cheese)
                    entType = 4;

                Sword* sword = dynamic_cast<Sword*>(object);
                if(sword)
                    entType = 5;

                Key* key = dynamic_cast<Key*>(object);
                if(key)
                    entType = 6;
                    
                sprite = Sprite(textures[entType+4]);
                sprite.setPosition(j * 32, i * 32);
                window->draw(sprite);
            }
        }
    }

}