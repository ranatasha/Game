#pragma once
#include <SFML/Graphics.hpp>
#include "Builder/Director.hpp"
#include "Builder/TypeBuilder1.hpp"
#include "Builder/TypeCreator1.hpp"
#include "Entity/Character/Player.hpp" 
#include "MapView.hpp"
#include "Rules/EnemyAmount.hpp"
#include "Rules/ItemAmount.hpp"
#include "Rules/EnemyGoal.hpp"
#include "Rules/NeedKey.hpp"
#include "Observer/ConsoleLogger.hpp"
#include "Observer/FileLogger.hpp"
#include "Observer/Logger.hpp"
#include "Command/ReadKey.hpp"
#include "Command/InvokerCommand.hpp"
#include "Command/SelectLogType.hpp"
#include "Memento/GameSnapshot.hpp"

#include <iostream>
#include <list>

using namespace sf;
template<class EnemyAmount, class ItemAmount, class EnemyGoal, class NeedKey>
class Game  
{	
	private:
		EnemyAmount enemyAmount;
		ItemAmount itemAmount;
		EnemyGoal enemyGoal;
		NeedKey needKey;

		Player* player_;
		std::list<Character*> enemies;
		std::list<Item*> items;
		Map* map;
	public:
		void startGame(){
			Director* pDirector = new Director();

			//create invoker
			InvokerCommand* invoker = new InvokerCommand();

			//selection the type of LogsOutput
			SelectLogType* selectLog = new SelectLogType();
			invoker->setCommand(selectLog);
			invoker->executeCommand();
			
			RenderWindow window(VideoMode(640, 640), "Game");

			//create map
			TypeBuilder1* pBuilder = new TypeBuilder1();
			pDirector->setBuilder(pBuilder);
			pDirector->createMap();
			Map* map = pBuilder->getMap();

			//create gameState
			GameState origState;
			std::list<Character*> empty1;
			empty1.clear();
			std::list<Item*> empty2;
			empty2.clear();
			origState = {nullptr, nullptr, 0, empty1, 0, empty2};
			origState.new_map = map;

			MapView* map_view = new MapView(map, &window);

			//create objects on map
			TypeCreator1* pCreator = new TypeCreator1(map);
			pDirector->setCreator(pCreator);
			pDirector->createObjects(this->enemyAmount.getCatCounter(), this->enemyAmount.getOwlCounter(), this->enemyAmount.getZombieCounter(), this->itemAmount.getCheeseCounter(), this->itemAmount.getSwordCounter(), itemAmount.getKeyCounter());
			Character* player = pCreator->getPlayer();
			origState.new_player = player;
			std::list<Character*> enemies = pCreator->getEnemies();
			origState.new_enemies = enemies;
			std::list<Item*> items = pCreator->getItems();
			origState.new_items = items;


			//create loggers
			std::list<Observer*> observers = createObservers(selectLog->getType(), player, enemies, items);
			
			//для mem_fn, чтобы вынести stepGame, но пришлось оставить эту идею
			//sf::Event event;
			// auto fn = std::mem_fn(&Game::stepGame);
			// auto accessX = std::mem_fn(&Player::getX);
			// auto accessY = std::mem_fn(&Player::getY);
			// auto fn_stepGame = std::bind(fn,map, player, enemies, std::placeholders::_1,std::placeholders::_2,std::placeholders::_5);
			// ReadKey* readkey = new ReadKey(&event, accessX, accessY, fn_stepGame);

			ReadKey* readkey = new ReadKey();
			readkey->setPressed(false);
			invoker->setCommand(readkey);

			//std::cout << "EnemiesCounter before: " << enemyAmount.getEnemiesCounter()<<std::endl;
			//std::cout << "ItemsCounter before: " << itemAmount.getItemsCounter()<<std::endl;
			
			while (window.isOpen())
			{
				map_view->printMap();
				sf::Event event;
				readkey->setEvent(&event);
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();

					if(!player->isAlive()){
						player->CreateMessage("\n~ THE END. PLAYER WAS KILLED :c ~\n");
						window.close();
					}
					int posX, posY;
					posX = player->getX();
					posY = player->getY();
					origState.new_n_enem = enemyAmount.getEnemiesCounter();
					origState.new_n_items = itemAmount.getItemsCounter();
					int x,y;
					if (posX == map->getWidth()-2 && posY == 1){
						if(needKey.isCompleted() && enemyGoal.isCompleted()){
							player->CreateMessage("\n~ MISSION COMPLETED! YOU ARE A WINNER! OUR CONGRATULATIONS :D ~\n");
							window.close();
						}
						else
							if(!needKey.isCompleted()&&!enemyGoal.isCompleted())
										player->CreateMessage("\n~ YOU NEED TO HAVE AN EXIT KEY and TO KILL ENEMIES. TRY AGAIN ~\n");
							else
								if(!enemyGoal.isCompleted()){
									player->CreateMessage("\n~ YOU NEED TO KILL ENEMIES. COMPLETE THE MISSION AND TRY AGAIN ~\n");
								}
								else
									if(!needKey.isCompleted())
										player->CreateMessage("\n~ YOU NEED TO HAVE AN EXIT KEY. TAKE IT AND TRY AGAIN ~\n");
									
					}
					//to do a stepGame
					invoker->executeCommand();

					Directions direction = readkey->getDirection();
					GameSnapshot* snap;
					switch (direction){
						case LEFT:
							x = posX -1;
							y = posY;
							stepGame(map, player, x, y, enemies);
							break;
						case UP:
							x = posX;
							y = posY - 1;
							stepGame(map, player, x, y, enemies);
							break;
						case RIGHT:
							x = posX + 1;
							y = posY;
							stepGame(map, player, x, y, enemies);
							break;
						case DOWN:
							x = posX;
							y = posY + 1;
							stepGame(map, player, x, y, enemies);
							break;
						case SAVE:
							{
							snap = new GameSnapshot(map, player, enemyAmount.getEnemiesCounter(), enemies, itemAmount.getItemsCounter(), items);
							snap->SaveGame();
							std::cout<<"OH\n";
							break;
							}
						case LOAD:
							{
							snap = new GameSnapshot(map, player, enemyAmount.getEnemiesCounter(), enemies, itemAmount.getItemsCounter(), items);
							snap->RestoreState(&origState);
							delete map_view;
							MapView* map_view = new MapView(map, &window);

							std::cout<<"AH\n";
							break;
							}
					}
					readkey->setPressed(false);
					readkey->setDirection(NO);
				}
				window.display();

			}
			delete map;
			delete map_view;
			delete pBuilder;
			delete pCreator;
			delete pDirector;
			delete player;
			delete invoker;


			for(std::list<Observer*>::iterator obs = observers.begin(); obs!=observers.end();++obs)
				delete *obs;

			for(std::list<Character*>::iterator enemy = enemies.begin(); enemy!=enemies.end();++enemy)
				delete *enemy;

			for(std::list<Item*>::iterator item = items.begin(); item!=items.end();++item)
				delete *item;
	    };


		void stepGame(Map* map, Character* player, int x, int y, std::list<Character*> enemies){
			player->move(map,x,y);
			if(dynamic_cast<Player*>(player)->getTakeItem()){
				itemAmount.reduceItemsCounter();
				//std::cout << "ItemsCounter after: " << itemAmount.getItemsCounter()<<std::endl;
				
			}
			if(dynamic_cast<Player*>(player)->hasKey()){
				needKey.setHasKeyTrue();
			}
			
			for(std::list<Character*>::iterator enemy = enemies.begin(); enemy!=enemies.end();++enemy){
				if((*enemy)->getX()!=(-1)){
					if(!(*enemy)->isAlive()){
						enemyGoal.addValue();
						enemyAmount.reduceEnemiesCounter();
						//std::cout << "EnemiesCounter after: "<<enemyAmount.getEnemiesCounter()<<std::endl;
						//enemy=enemies.erase(enemy);
						//enemy--;
						(*enemy)->setX(-1);
						(*enemy)->setY(-1);
						continue;
					}
					(*enemy)->move(map);
				}
			}
			
		};

		std::list<Observer*> createObservers(LogsType logType, Character* player, std::list<Character*> enemies, std::list<Item*> items){
			std::list<Observer*> observers;
			if(logType==CONSOLE || logType==CONS_FILE){
				ConsoleLogger* consLog = new ConsoleLogger();
				player->Attach(consLog);
				for(std::list<Character*>::iterator enemy = enemies.begin(); enemy!=enemies.end();++enemy){
					(*enemy)->Attach(consLog);
				}
				observers.push_back(consLog);
			}
			if(logType==FILETYPE || logType==CONS_FILE){
				FileLogger* fileLog = new FileLogger();
				player->Attach(fileLog);
				for(std::list<Character*>::iterator enemy = enemies.begin(); enemy!=enemies.end();++enemy){
					(*enemy)->Attach(fileLog);
				}
				observers.push_back(fileLog);
			}
			return observers;
		};

};