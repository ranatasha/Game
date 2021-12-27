#pragma once
#include "Cell.h"

class Map {
private:
    int width;
    int height;
    Cell** field;

public:
    Map();
    Map(const Map& other);
    Map(Map&& other);
    Map& operator=(const Map& other);
    Map& operator=(Map&& other);

    int getWidth()const{return width;}
    int getHeight() const{return height;}

    Cell** getFieldPtr() {return field;}
    
    ~Map();
};

