#include "TypeCreator1.hpp"
#include <iostream>  
	
TypeCreator1::TypeCreator1(Map* map){
    this->map = map;
}

void TypeCreator1::ResetEnemies(){
    std::list<Character*> new_v;
    this->enemies = new_v;
}

void TypeCreator1::ResetItems(){
    std::list<Item*> new_v;
    this->items = new_v;
}

void TypeCreator1::CreatePlayer(){
    int x=1, y=18;                                  //координаты клетки входа
    Character* player = new Player(x,y);
    map->getFieldPtr()[y][x].setEntity(player);
    this->player = player;

}

void TypeCreator1::CreateEnemies(int cat, int owl, int zombie){
    std::list<Character*> result;
    CatFactory* catFactory = new CatFactory; 
    std::list<Character*> tmp = catFactory->createCharacter(map,cat);
    result.merge(tmp);


    // for(int i = 0; i<result.size(); i++)
    //     this->enemies.push_back(result[i]);
    delete catFactory;
    // result.clear();

    OwlFactory* owlFactory = new OwlFactory; 
    std::list<Character*> tmp1 = owlFactory->createCharacter(map, owl);
    result.merge(tmp1);

    // for(int i = 0; i<result.size(); i++)
    //     this->enemies.push_back(result1[i]);
    delete owlFactory;
    // result1.clear();

    ZombieFactory* zombieFactory = new ZombieFactory; 
    std::list<Character*> tmp2 = zombieFactory->createCharacter(map, zombie);
    result.merge(tmp2);

    // for(int i = 0; i<result.size(); i++)
    //     this->enemies.push_back(result2[i]);
    delete zombieFactory;
    // result2.clear();

    this->enemies=result;
    //result.clear();
}

void TypeCreator1::CreateItems(int cheese, int sword, int key){
    std::list<Item*> result;
    CheeseFactory* cheeseFactory = new CheeseFactory; 
    std::list<Item*> tmp = cheeseFactory->createItem(map,cheese);
    result.merge(tmp);
    delete cheeseFactory;

    SwordFactory* swordFactory = new SwordFactory; 
    std::list<Item*> tmp1 = swordFactory->createItem(map, sword);
    result.merge(tmp1);
    delete swordFactory;

    KeyFactory* keyFactory = new KeyFactory; 
    std::list<Item*> tmp2 = keyFactory->createItem(map, key);
    result.merge(tmp2);
    delete keyFactory;

    this->items=result;
    result.clear();
}

Character* TypeCreator1::getPlayer(){
    return this->player;
}

std::list<Character*> TypeCreator1::getEnemies(){
    std::list<Character*> result = this->enemies;
    this->ResetEnemies();
    return result;
}

std::list<Item*> TypeCreator1::getItems(){
    std::list<Item*> result = this->items;
    this->ResetItems();
    return result;
}
	
TypeCreator1::~TypeCreator1(){
    this->enemies.clear();
    this->items.clear();
}