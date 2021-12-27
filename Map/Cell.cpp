#include "Cell.h"
#include <SFML/Graphics.hpp>

bool Cell::hasEntity() const{              //проверка на не nullptr. Всегда выполняется программистом перед вызовом getEntity()
    if(pEntity)
        return true;
    return false;
}

void Cell::setEntity(Entity* pEntity){
    if(pEntity){
        delete this->pEntity;
        this->pEntity = pEntity;
    }
    else
        this->pEntity = nullptr;
}


Cell::Cell(States state, Entity* pEntity){
    this->state = state;
    this->pEntity = nullptr;
}

//перегрузка конструктора копирования
Cell::Cell(const Cell& other): state(other.state){
    if (other.hasEntity()){ //проверка на не nullptr
        delete pEntity; 
        pEntity = other.getEntity();
    }
    else
        pEntity = nullptr; 
 }

//перегрузка оператора присваивания копированием
Cell& Cell::operator=(const Cell& other){
    if(this == &other)
        return *this;
    state = other.getState();

    if (other.hasEntity()){ //проверка на не nullptr
        delete pEntity;
        pEntity = other.getEntity();
    }
    else
        pEntity = nullptr;
    return *this;
}