#include "Map.h"
#include <iostream>



Map::Map() {
    width = 20;
    height = 20;
    
    field = new Cell* [height];  //массив указателей на клетки
    for(int i=0;i<height;i++)
        field[i] = new Cell [width];   //каждому указателю выделяем память под массив клеток
}

//конструктор копирования
Map::Map(const Map& other): width(other.width), height(other.height){
    this->field = new Cell* [height];
    for(int i=0;i<height;i++){
        field[i] = new Cell [width];
        for(int j=0;j<width;j++)
            field[i][j] = other.field[i][j];
    }
}

//перегрузка оператора присваивания копированием
Map& Map::operator=(const Map& other){
    if(this != &other){
        // for(int i=0; i<height;i++) подчищать память не надо, так как массив фиксированного размера
        //     delete[] field[i];
        width = other.width;
        height = other.height;

        for(int i=0;i<height;i++){
            for(int j=0;j>width;j++){
                field[i][j] = other.field[i][j];
            }
        }
    }
    return *this;
}

//конструктор перемещения
Map::Map(Map&& other){
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(field, other.field);
}

//перегрузка оператора присваивания перемещением
Map& Map::operator=(Map&& other){
    if(this != &other){
        width = other.width;
        height = other.height;

        for(int i=0;i<height;i++)
                std::swap(field[i], other.field[i]);
    }
    return *this;
}

Map::~Map() {
    for(int i=0; i<height;i++)
        delete[] field[i];
    //delete[] field;
}