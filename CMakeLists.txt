cmake_minimum_required(VERSION 3.16)
project(game_lab3)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS graphics system window REQUIRED)
add_executable(game_lab3 main.cpp ./Builder/Director.cpp ./Builder/TypeBuilder1.cpp ./Map/Map.cpp ./Map/Cell.cpp ./Entity/Entity.cpp ./Entity/Character/Player.cpp ./Entity/Character/Character.cpp ./Entity/Character/Enemy/Cat.cpp ./Entity/Character/Enemy/Enemy.cpp ./Entity/Character/Enemy/Owl.cpp ./Entity/Character/Enemy/Zombie.cpp ./Entity/Item/Cheese.cpp ./Entity/Item/Key.cpp ./Entity/Item/Item.cpp ./Entity/Item/Sword.cpp ./Factory/CharacterFactory/CatFactory.cpp ./Factory/CharacterFactory/CharacterFactory.cpp ./Factory/CharacterFactory/OwlFactory.cpp ./Factory/CharacterFactory/ZombieFactory.cpp ./Factory/ItemFactory/CheeseFactory.cpp ./Factory/ItemFactory/KeyFactory.cpp ./Factory/ItemFactory/ItemFactory.cpp ./Factory/ItemFactory/SwordFactory.cpp MapView.cpp ./Builder/Creator.cpp ./Builder/TypeCreator1.cpp ./Observer/Observable.cpp ./Observer/Subject.cpp ./Observer/Observer.cpp  ./Observer/ConsoleLogger.cpp ./Observer/FileLogger.cpp ./Observer/Logger.cpp ./Command/Command.cpp ./Command/InvokerCommand.cpp ./Command/ReadKey.cpp ./Command/SelectLogType.cpp ./Memento/GameSnapshot.cpp)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(game_lab3 sfml-graphics sfml-window sfml-system)
