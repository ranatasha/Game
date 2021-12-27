#include "GameSnapshot.hpp"  
	
GameSnapshot::GameSnapshot(Map* map, Character* player, int n_enemies, std::list<Character*> enemies, int n_items, std::list<Item*> items)
{
    // size_field/state_cell // x/y/h_player/d_player/k_player // n_enemies/x/y/type_enemy/h_enemy/d_enemy // n_items/x/y/type_item
	std::string data = "";

    // save field_state
    data += std::to_string(map->getWidth());
    data += "\n";

    for(int i=0; i<map->getHeight();i++){
        for(int j=0; j< map->getWidth();j++){
            data += std::to_string(map->getFieldPtr()[i][j].getState());
            data += "\n";
        }
    }

    //save player_state
    data += std::to_string(player->getX());
    data += "\n"; 
    data += std::to_string(player->getY());
    data += "\n"; 
    data += std::to_string(player->getHealth());
    data += "\n";
    data += std::to_string(player->getDamage());
    data += "\n";
    data += std::to_string(dynamic_cast<Player*>(player)->hasKey()); 
    data += "\n";
    
    //save enemies_state
    data += std::to_string(n_enemies);
    data += "\n";
    for(std::list<Character*>::iterator enemy = enemies.begin(); enemy!=enemies.end();++enemy){
        if((*enemy)->getX()!=(-1)){
            data += std::to_string((*enemy)->getX());
            data += "\n";
            data += std::to_string((*enemy)->getY());
            data += "\n";
            data += std::to_string((*enemy)->getType());
            data += "\n";
            data += std::to_string((*enemy)->getHealth());
            data += "\n";
            data += std::to_string((*enemy)->getDamage());
            data += "\n";
        }
    }

    //save items_state
    data += std::to_string(n_items);
    data += "\n";
    for(std::list<Item*>::iterator item = items.begin(); item!=items.end();++item){
        if((*item)->getX()!=(-1)){
            data += std::to_string((*item)->getX());
            data += "\n";
            data += std::to_string((*item)->getY());
            data += "\n";
            data += std::to_string((*item)->getType());
            data += "\n";
        }
    }

    // setState
    this->state = data;

    std::list<Character*> empty1;
    empty1.clear();
    std::list<Item*> empty2;
    empty2.clear();
    GameState loaded;
    loaded = {nullptr, nullptr, 0, empty1, 0, empty2};
    this->loadedState = &loaded;
}

void GameSnapshot::SaveGame(){
    std::ofstream saver;
    saver.open("saved_game.txt");
    saver << state;
    saver.close();
}

void GameSnapshot::RestoreState(GameState* origState){
    // size_field/state_cell // x/y/h_player/d_player/k_player // n_enemies/x/y/type_enemy/h_enemy/d_enemy // n_items/x/y/type_item
    std::ifstream loader("saved_game.txt");

    if(!loader)
        std::cout << "ERROR OPENING FILE!!!!!";
        
    int size_field, state_cell,x_player,y_player,h_player,d_player,k_player,n_enemies,x_enemy,y_enemy,type_enemy,h_enemy,d_enemy,n_items,x_item,y_item,type_item;
    
    // load fieldGame
    std::cout<<"hello";
    Map* new_map = new Map();
    if(loader>>size_field){
        for(int i=0;i<size_field;i++){
            for(int j=0;j<size_field;j++){
                if(loader>>state_cell){
                    switch(state_cell){
                        case IMPASSABLE:
                            new_map->getFieldPtr()[i][j].setState(IMPASSABLE);
                            break;
                        case PASSABLE:
                            new_map->getFieldPtr()[i][j].setState(PASSABLE);
                            break;
                        case ENTER:
                            new_map->getFieldPtr()[i][j].setState(ENTER);
                            break;
                        case EXIT:
                            new_map->getFieldPtr()[i][j].setState(EXIT);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        loadedState->new_map = new_map;
    }
    
    // load playerGame
    Character* new_player;
    if(loader>>x_player>>y_player){
        if(x_player>=1 && x_player<=18 && y_player>=1 && y_player<=18){
            if(loader>>h_player){
                if(loader>>d_player){
                    if(d_player>=4){
                        if(loader>>k_player){
                            if(k_player == 0 || k_player == 1){
                                new_player = new Player(x_player,y_player,h_player,d_player, k_player);
                                new_map->getFieldPtr()[y_player][x_player].setEntity(new_player);
                                loadedState->new_player = new_player;
                            }
                        }
                    }
                }
            }
        }
        loadedState->new_player = new_player;
            
    }

    // load enemiesGame
    std::list<Character*> new_enemies;
    Character* cat;
    Character* owl;
    Character* zombie;
    if(loader>>n_enemies){
        if(n_enemies>=0){
            loadedState->new_n_items = n_items;
            for(int i=0;i<n_enemies;i++){
                if(loader>>x_enemy>>y_enemy){
                    if(x_enemy>=1 && x_enemy<=18 && y_enemy>=1 && y_enemy<=18){
                        if(loader>>type_enemy){
                            switch (type_enemy){
                                case CAT:
                                    if(loader>>h_enemy>>d_enemy){
                                        cat = new Cat(x_enemy,y_enemy,h_enemy,d_enemy);
                                        new_map->getFieldPtr()[y_enemy][x_enemy].setEntity(cat);
                                        new_enemies.push_back(cat);
                                    }
                                    break;
                                case OWL:
                                    if(loader>>h_enemy>>d_enemy){
                                            owl = new Owl(x_enemy,y_enemy,h_enemy,d_enemy);
                                            new_map->getFieldPtr()[y_enemy][x_enemy].setEntity(owl);
                                            new_enemies.push_back(owl);
                                    }
                                    break;

                                case ZOMBIE:
                                    if(loader>>h_enemy>>d_enemy){
                                            zombie = new Zombie(x_enemy,y_enemy,h_enemy,d_enemy);
                                            new_map->getFieldPtr()[y_enemy][x_enemy].setEntity(zombie);
                                            new_enemies.push_back(zombie);
                                    }
                                    break;
                                
                                default:
                                    break;
                            }
                        }
                    }
                }
            }
        }
        loadedState->new_enemies = new_enemies;
    }

    // load itemsGame
    std::list<Item*> new_items;
    Item* cheese;
    Item* sword;
    Item* key;
    if(loader>>n_items){
        if(n_items>=0){
            loadedState->new_n_items = n_items;
            for(int i=0;i<n_items;i++){
                if(loader>>x_item>>y_item){
                    if(loader>>type_item){
                        switch (type_item){
                            case CHEESE:
                                cheese = new Cheese(x_item,y_item);
                                new_map->getFieldPtr()[y_item][x_item].setEntity(cheese);
                                new_items.push_back(cheese);
                                break;
                            case SWORD:
                                sword = new Sword(x_item,y_item);
                                new_map->getFieldPtr()[y_item][x_item].setEntity(sword);
                                new_items.push_back(sword);
                                break;

                            case KEY:
                                key = new Key(x_item,y_item);
                                new_map->getFieldPtr()[y_item][x_item].setEntity(key);
                                new_items.push_back(key);
                                break;
                            
                            default:
                                break;
                        }
                    }
                }
                
            }
        }
        loadedState->new_items = new_items;
    }
    
    // changeState
    this->changeState(origState); 
    loader.close();
}

void GameSnapshot::changeState(GameState* origState){
    delete origState->new_map;
    origState->new_map = loadedState->new_map;
    delete origState->new_player;
    origState->new_player = loadedState->new_player;
    origState->new_n_enem = loadedState->new_n_enem;
    origState->new_n_items = loadedState->new_n_items;

    for(std::list<Character*>::iterator enemy = origState->new_enemies.begin(); enemy!=origState->new_enemies.end();++enemy)
		delete *enemy;
    origState->new_enemies.clear();
    for(std::list<Character*>::iterator enemy = loadedState->new_enemies.begin(); enemy!=loadedState->new_enemies.end();++enemy)
		origState->new_enemies.push_back(*enemy);
    

    for(std::list<Item*>::iterator item = origState->new_items.begin(); item!=origState->new_items.end();++item)
        delete *item;
    origState->new_items.clear();
    for(std::list<Item*>::iterator item = loadedState->new_items.begin(); item!=loadedState->new_items.end();++item)
		origState->new_items.push_back(*item);

}