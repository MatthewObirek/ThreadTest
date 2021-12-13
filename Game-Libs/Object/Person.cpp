#include "Person.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <math.h>

#include <Debug.h>

Person::Person(int x, int y, float Money, std::string name, std::string desc)
    : Object(x, y, name, desc), Money(Money), itemWanted(Item()), hasBought(false), Status(isStanding)
{
    isMovingX = false;
    isMovingY = false;    
    store = nullptr;
    LOG("store member not set" );
}

Person::~Person()
{
    LOG(this->name << " Is leaving!!");
}

Store *Person::getStore()
{
    ptr_call(this->store, this->name);
    return this->store;
}

void Person::printInfo()
{
    std::cout << this->name << " ( " << this->x << ", " << this->y << ") ";
    std::cout << "is currently";
    switch(this->Status)
    {
    case Person::isSelling: std::cout << " Selling" << std::endl;
    break;
    case Person::isBuying:  std::cout << " Buying" << std::endl;
    break;
    case Person::isMoving:  std::cout << " Moving" << std::endl;
    break;
    case Person::isStanding:
    default:    std::cout << " Standing" << std::endl;
    }    
}

float Person::pay(float cost) 
{
    this->Money -= cost;
    return cost; 
}

void Person::moveTo(Object& object)
{
    this->Status = isMoving;
    this->isMovingX = true;
    this->isMovingY = true;
    while(this->isMovingX || this->isMovingY)
    {

        //moves x value
        if (this->getX() < object.getX())
           this->moveX(1);
        else if (this->getX() > object.getX())
            this->moveX(-1);
        else
            this->isMovingX = false;
        
        //move y value
        if (this->getY() < object.getY())
            this->moveY(1);
        else if (this->getY() > object.getY())
           this->moveY(-1);
        else
            this->isMovingY = false;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    this->Status = isStanding;
}
void Person::grabItem(Store* store, int item, int amm)
{
    this->itemWanted = store->giveItem(this->desire, amm);      //BUG will have negative stock
}

void Person::buyFrom(Person &person)
{
    this->setStatus(isBuying);
    person.setStatus(isSelling);
    float cost = person.getStore()->getCostOf(this->desire);
    if(!(person.getStore()->itemStock(this->desire) > 0) || (this->Money < cost ))
    {
        this->setStatus();
        person.setStatus();
        return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    person.getStore()->incrMoney(this->pay(cost));
    LOG("Item bought");
    this->setStatus();
    person.setStatus();
    this->hasBought = true;
}