#pragma once
#include <vector>

#include "Object.h"
#include "Person.h"
#include "Store.h"

class Queue {
private:
    struct Node{
        Node(Person* person = nullptr, Node* next = nullptr);
        ~Node();

        Person* current;
        Node* next;
    };
    Node* start;
    Node* end;
    int size;
public:
    Queue() = default;

    int inline getLength() { return this->size; }

    void Add(Person* person);
    Person* Remove();

};

class Map
{
private:
    Store *store;       //Pointer
    Object *Structs;    //Array
    Person *Workers;    //Array

    Queue cashLine;
    int StructSize, WorkerSize;
    volatile bool mapRunning;

    std::vector<Person> Customers;
public:

    Map(Object *Structs, int StructSize, Person *Workers, int WorkerSize);

    void SpawnCustomer();
    void run();
    void inline stopRunning() { this->mapRunning = false; }
    void setStore(Store &store);
    Store *getStore();  //ONLY EVER USE THIS FUNC TOGET STORE

    void printInfo();

};

