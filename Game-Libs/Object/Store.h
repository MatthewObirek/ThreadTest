#pragma once
#include "Object.h"
#include "Item.h"
//#include "Person.h"

class Store
{
private:
    float Money;
    std::string name;
    Item * items;

    int itemsSize;
public:

    Store(float Money = 0, Item * items = nullptr, int itemsSize = 0);

    void inline incrMoney(float amm) { this->Money += amm; }
    std::string inline getName() { return this->name; }
    
    int inline getItemSize() { return this->itemsSize; }

    Item giveItem(int i, int amm); 
    
    float inline getCostOf(int i) { return this->items[i].cost; }
    int inline itemStock(int i) { return (this->items[i].stock); }
};