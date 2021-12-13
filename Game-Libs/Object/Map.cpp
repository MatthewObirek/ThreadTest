#include "Map.h"
#include <thread>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include <Debug.h>

Map::Map(Object *Structs, int StructSize, Person *Workers, int WorkerSize)
    :Structs(Structs), Workers(Workers), StructSize(StructSize), WorkerSize(WorkerSize), store(nullptr), mapRunning(false), cashLine(Queue())
{
    Customers.reserve(32);
    LOG("store member not set!!"); 
}

void Map::SpawnCustomer()
{
    if(Customers.size() < Customers.capacity())
    {
        Customers.emplace_back(Structs[0].getX()+1, Structs[0].getY()+1,100.0f , std::to_string(Customers.size()), "will buy stuff");
        std::srand(std::time(nullptr));
        int x = std::rand() % (this->getStore()->getItemSize());
        Customers.back().setDesire(x);
    }
    else
    {
        LOG("At Capacity!! No more customers Allowed!!");
    }
}

void Map::run()
{
    this->SpawnCustomer();

    int x = 0;
    this->mapRunning = true;
    while(this->mapRunning)
    {   
        
        LOG(x++);
        for (int i = 0; i < Customers.size(); i++)
        {
            switch(Customers.at(i).getStatus())
            {
            case Person::isBuying: break;
            case Person::isMoving: break;
            case Person::isSelling: break;
            case Person::isStanding:
            defalut:
                if (Customers.at(i).hasBought)
                {
                    if((Customers.at(i).getX() == Structs[0].getX()) && (Customers.at(i).getY() == Structs[0].getY()))
                    {
                        Customers.erase(Customers.begin() + i);
                        this->mapRunning = (Customers.size() < 1) ? false : true;
                        if (!this->mapRunning) break;
                    }
                    else
                    {
                        std::thread mover(&Person::moveTo, std::ref(Customers.at(i)), std::ref(Structs[0]));
                        mover.detach();
                    }

                }
                else if (Customers.at(i).getItem().stock > 0)
                {
                    if((Customers.at(i).getX() == Structs[1].getX()) && (Customers.at(i).getY() == Structs[1].getY()))
                    {
                        cashLine.Add(&Customers.at(i));
                        if(Workers[0].getStatus() == Person::isStanding)
                        {
                            std::thread buyer(&Person::buyFrom, std::ref((*cashLine.Remove())), std::ref(Workers[0]));
                            buyer.detach();
                        }
                    }
                    else
                    {
                        std::thread mover(&Person::moveTo, std::ref(Customers.at(i)), std::ref(Structs[1]));
                        mover.detach();
                    }
                }
                else
                {
                    
                    int x = 2 + Customers.at(i).getDesire();
                    x = (x > this->StructSize)? this->StructSize - 1 : x; 

                    if((Customers.at(i).getX() == Structs[x].getX()) && (Customers.at(i).getY() == Structs[x].getY()))
                    {
                        Customers.at(i).grabItem(this->store, Customers.at(i).getDesire());
                    }
                    else
                    {
                        std::thread mover(&Person::moveTo, std::ref(Customers.at(i)), std::ref(Structs[x]));
                        mover.detach();
                    }
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
}

void Map::setStore(Store &store)
{
    this->store = &store;
    for (int i = 0; i < WorkerSize; i++)
    {
        Workers[i].setStore(store);
    }
}


Store *Map::getStore()
{
    ptr_call(this->store, "0map");   //in the future change to store ptr array and call which store!
    return this->store;
}

void Map::printInfo()
{
    //LOG(this->mapRunning);
    int x =0;

    while(this->mapRunning)
    {
        std::cout << "Workers" << std::endl;
        for (int i = 0; i < WorkerSize; i++)
        {
            Workers[i].printInfo();
        }
        std::cout << std::endl << "Customers" << std::endl;
        for (int i = 0; i < Customers.size(); i++)
        {
            Customers.at(i).printInfo(); 
        }
        x++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("clear");
    }
}





Queue::Node::Node(Person* person, Node* next)
    : current(person), next(next)
{
    LOG("Node created");
}

Queue::Node::~Node()
{
    LOG("Node DELETED");
}


void Queue::Add(Person* person) 
{
    size++;
    Node *temp = new Node;
    LOG(temp);
    temp->current = person;
    if(start == nullptr)
    {
        temp->next = nullptr;
        this->start = temp;
        this->end = temp;
    }
    else
    {
        this->end->next = temp;
        temp->next = this->end;
        this->end = temp;
    }
}

Person* Queue::Remove()
{
    size--;
    if(this->start == nullptr)
    {
        return nullptr;
    }
    Person* temp = this->start->current;
    Node* Tnode = this->start;
    this->start = this->start->next;
    delete Tnode;
    return temp;
}
