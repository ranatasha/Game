#include "TypeBuilder1.hpp"

void TypeBuilder1::Reset(){
	this->map = new Map();
}

TypeBuilder1::TypeBuilder1(){
	this->Reset();
}

void TypeBuilder1::FillEmptyField(){
	int y = this->map->getHeight();
	int x = this->map->getWidth();
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			this->map->getFieldPtr()[i][j].setState(PASSABLE);
		}
	}
}

void TypeBuilder1::CreateObstacles(){
	int y = this->map->getHeight();
	int x = this->map->getWidth();
	for (int i = 0; i < y; i++) {
        this->map->getFieldPtr()[0][i].setState(IMPASSABLE);
        this->map->getFieldPtr()[y-1][i].setState(IMPASSABLE);
        this->map->getFieldPtr()[i][0].setState(IMPASSABLE);
        this->map->getFieldPtr()[i][x-1].setState(IMPASSABLE);
    }

    for (int i = 2; i <= y-1-2; i = i + 3) {
        for (int j = 1; j <= x-1-2; j = j + 3) {
            this->map->getFieldPtr()[i][j].setState(IMPASSABLE);
        }
    }
}

void TypeBuilder1::CreateExits(){
	int width = this->map->getWidth();
	int y1 = width-2, x1 = 1, y2 = 1, x2 = width-2;
	
	this->map->getFieldPtr()[y1][x1].setState(ENTER);
	this->map->getFieldPtr()[y2][x2].setState(EXIT);
}

// void TypeBuilder1::CreatePlayer(){
// 	int posX=1, posY=this->map->getHeight()-2;
// 	PlayerFactory* playerFactory = new PlayerFactory;
// 	Entity* player = playerFactory->createCharacter(posX,posY);
// 	this->map->getFieldPtr()[posY][posX].setEntity(player);
// 	delete playerFactory;
// }

// void TypeBuilder1::CreateEvil(){
// 	Entity* enemies[3];
// 	CatFactory* catFactory = new CatFactory; 
// 	int posX=3, posY=16;
// 	enemies[0] = catFactory->createCharacter(posX,posY);
// 	this->map->getFieldPtr()[posY][posX].setEntity(enemies[0]);
// 	delete catFactory;

// 	OwlFactory* owlFactory = new OwlFactory; 
// 	posX=1, posY=10;
// 	enemies[1] = owlFactory->createCharacter(posX,posY);
// 	this->map->getFieldPtr()[posY][posX].setEntity(enemies[1]);
// 	delete owlFactory;

// 	ZombieFactory* zombieFactory = new ZombieFactory; 
// 	posX=8, posY=1;
// 	enemies[2] = zombieFactory->createCharacter(posX,posY);
// 	this->map->getFieldPtr()[posY][posX].setEntity(enemies[2]);
// 	delete zombieFactory;
// }

// void TypeBuilder1::CreateItems(){
// 	Entity* items[3];
// 	CheeseFactory* cheeseFactory = new CheeseFactory; 
// 	int posX=6, posY=13;
// 	items[0] = cheeseFactory->createItem();
// 	this->map->getFieldPtr()[posY][posX].setEntity(items[0]);
// 	delete cheeseFactory;

// 	SwordFactory* swordFactory = new SwordFactory; 
// 	posX=9, posY=3;
// 	items[1] = swordFactory->createItem();
// 	this->map->getFieldPtr()[posY][posX].setEntity(items[1]);
// 	delete swordFactory;

// 	KeyFactory* keyFactory = new keyFactory; 
// 	posX=14, posY=18;
// 	items[2] = helmetFactory->createItem();
// 	this->map->getFieldPtr()[posY][posX].setEntity(items[2]);
// 	delete keyFactory;

// }

Map* TypeBuilder1::getMap(){
	Map* result = this->map;
	this->Reset();
	return result;
}

TypeBuilder1::~TypeBuilder1(){
	delete map;
}