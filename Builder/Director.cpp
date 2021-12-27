#include "Director.hpp"  
	
void Director::setBuilder(Builder* pBuilder){
    this->pBuilder = pBuilder;
}

void Director::setCreator(Creator* pCreator){
    this->pCreator = pCreator;
}

void Director::createMap(){
    pBuilder->FillEmptyField();
    pBuilder->CreateObstacles();
    pBuilder->CreateExits();
}

void Director::createObjects(int cat, int owl, int zombie, int cheese, int sword, int key){
    pCreator->CreatePlayer();
    pCreator->CreateEnemies(cat, owl, zombie);
    pCreator->CreateItems(cheese, sword, key);
}