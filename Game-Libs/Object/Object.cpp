#include "Object.h"

Object::Object(int x, int y, std::string name, std::string desc)
    : x(x), y(y), name(name), desc(desc) 
{
    std::cout << this->name << " ( " << this->x << ", " << this->y << " )";
    std::cout << " Has been created!!" << std::endl;
}

