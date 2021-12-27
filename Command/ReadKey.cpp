#include "ReadKey.hpp"
//ReadKey::ReadKey(sf::Event* event, std::function<int()> accessX, std::function<int()> accessY, std::function<void(int x, int y)> move_func){
    // this->setPressed(false);
    // this->setEvent(event);
    // this->setDirection(NO);
    // this->move_func = move_func;
    // this->accessX = accessX;
    // this->accessY = accessY;
//}

void ReadKey::execute(){
    int coordX, coordY, x, y;
    if(event->type == sf::Event::KeyPressed){
        if((event->key.code == sf::Keyboard::Left || event->key.code == sf::Keyboard::A) && pressed == false){
            this->setPressed(true);
            this->setDirection(LEFT);
        }
        if((event->key.code == sf::Keyboard::Up || event->key.code == sf::Keyboard::W) && pressed == false){
            this->setPressed(true);
            this->setDirection(UP);
        }
        if((event->key.code == sf::Keyboard::Right || event->key.code == sf::Keyboard::D) && pressed == false){
            this->setPressed(true);
            this->setDirection(RIGHT);
        }
        if((event->key.code == sf::Keyboard::Down || event->key.code == sf::Keyboard::S)&& pressed == false){
            this->setPressed(true);
            this->setDirection(DOWN);
        }
        if(event->key.code == sf::Keyboard::Q && pressed == false){
            this->setPressed(true);
            this->setDirection(SAVE);
        }
        if(event->key.code == sf::Keyboard::E && pressed == false){
            this->setPressed(true);
            this->setDirection(LOAD);
        }
    }
    if(event->type == sf::Event::KeyReleased){
        this->setPressed(false);
        this->setDirection(NO);
    }
};