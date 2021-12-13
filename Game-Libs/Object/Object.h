#pragma once 
#include <iostream>
#include <string>

#include <Debug.h>
class Object
{
public:
    int x, y;
    std::string name, desc;


    Object(int x = 0, int y = 0, std::string name = "NULL", std::string desc = "NULL");

    int inline getX() { return this->x; }
    int inline getY() { return this->y; }
    std::string inline getName() { return this->name; }
    std::string inline getDisc() { return this->desc; }

    void inline moveX(int amm) { this->x += amm; }
    void inline moveY(int amm) { this->y += amm; }

    void inline setX(int x) { this->x = x; }
    void inline setY(int y) { this->y = y; }
    void inline setName(std::string name) { this->name = name; }
    void inline setDisc(std::string desc) { this->desc = desc; }

};