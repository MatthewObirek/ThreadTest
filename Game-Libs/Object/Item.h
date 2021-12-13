#pragma once

#include <Debug.h>

struct Item
{
public:
    float cost;
    int stock;
    //Constructors and Operators
    Item(float cost = 9999.99, int stock = 0);
    ~Item();
    Item(const Item& other);
    Item(Item&& other) noexcept;
    Item& operator=(const Item& other);
    Item& operator=(Item&& other) noexcept;

};