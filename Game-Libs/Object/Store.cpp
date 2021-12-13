#include "Store.h"

Store::Store(float Money, Item * items, int itemsSize) 
    : Money(Money), items(items), itemsSize(itemsSize), name("store")
{
    LOG(this->name << " created!!");
}

Item Store::giveItem(int i, int amm)
{
    if (items[i].stock == 0)
    {
        return Item();
    }
    else if (items[i].stock > amm)
    {
        items[i].stock -= amm;
        return Item(items[i].cost, amm);
    }
    else
    {
        Item tempItem = items[i];
        items[i].stock = 0;
        return tempItem;
    }
}

