#pragma once
#include "../Observer/Subject.hpp"

class Entity: public Subject 
{           
    public:                      
        virtual void interact(Entity& entity) = 0;
        virtual ~Entity() = default;
};                                      
