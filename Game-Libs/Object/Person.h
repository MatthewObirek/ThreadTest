#pragma once 
#include "Object.h"
#include "Item.h"
#include "Store.h"



class Person : public Object
{
public:
    enum status
    {
        isStanding, isMoving, isBuying, isSelling
    };
    bool hasBought;
private:
    Item itemWanted;
    status Status;
    bool isMovingX, isMovingY;
    int desire;
    float Money;
    Store *store;    
public:

    

    Person(int x = 0, int y = 0, float Money = 0.0f,std::string name = "NULL", std::string desc = "NULL");
    ~Person();

    void setStore(Store &store) { this->store = &store; }
    Store *getStore();

    int inline getDesire() { return this->desire; }
    void inline setDesire(int x) { this->desire = x; }

    Item inline getItem() { return this->itemWanted; }

    void inline setStatus(status Status = isStanding) { this->Status = Status; }
    status inline getStatus() { return this->Status; }
    
    void printInfo();
    float pay(float cost);

    void moveTo(Object& object);
    void grabItem(Store* store, int item, int amm = 1);
    
    void buyFrom(Person &person);
};