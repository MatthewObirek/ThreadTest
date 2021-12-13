#include "Item.h"
#include <iostream>

Item::Item(float cost, int stock) : cost(cost), stock(stock) 
{
    LOG("Item created ( " << this->cost << ", " << this->stock << " )");
}

Item::~Item()
{
    LOG("Item destroyed!!");
}

Item::Item(const Item& other) : cost(other.cost), stock(other.stock)
{
    LOG("Item copyed ( " << this->cost << ", " << this->stock << " )");
}

Item::Item(Item&& other) noexcept : cost(other.cost), stock(other.stock) 
{
    LOG("Item moved ( " << this->cost << ", " << this->stock << " )");
    other.cost = 0;
    other.stock = 0;
}

Item& Item::operator=(const Item& other)
{
    LOG("Item copy operator used");
    return *this = Item(other);
}

Item& Item::operator=(Item&& other) noexcept
{
    LOG("Item move operator used");
    this->cost = other.cost;
    this->stock = other.stock;
    other.cost = 0;
    other.stock = 0;
    return *this;
}