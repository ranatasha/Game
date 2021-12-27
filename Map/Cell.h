#pragma once
#include "../Entity/Entity.h"
#include <SFML/Graphics.hpp>

enum States{IMPASSABLE,PASSABLE,ENTER,EXIT};

class Cell {
private:
    States state;
    Entity* pEntity;

public:
    Cell(States state = PASSABLE,  Entity* pEntity= nullptr);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);

    States getState() const{return state;}

    void setState(States state){this->state = state;}

    bool hasEntity() const;
    Entity* getEntity(){return pEntity;}
    Entity* getEntity() const{return pEntity;}
    Entity& getEntityLink(){return *pEntity;}
    void setEntity(Entity* pEntity);
};
