#include <iostream>
#include <chrono>
#include <thread>

#include <Object.h>
#include <Person.h>
#include <Store.h>
#include <Map.h>

#include <Debug.h>
//#include <Item.h>
/**

????????????????/???????????????????????? *@todo Add MUTEX

fix customer nameing and out of stock
static int Map::customerCount = 0;
customerCount++; 


fix looping to fix std::out_of_bounds::stdVector --> mostly fixed??
///////!!!!DONE!!!!///////
IMPLEMENT MAP FULLY AND SET UP RUN THREAD; SPAWN THREAD done
Fix loop counting, and allow for force quitting
have commands (spawn, quit)

LATER DATE-->add array ll storage to Structs for items, 

*/
Item Inventory[] = {Item(5.99f, 7),
                    Item(9.99f, 3),
                    Item(1.99f, 9),
                    Item(2.49f, 6),
                    Item(8.49f, 5) };

Object Structs[] = {Object(1, 7, "door", "Entracne and exit"),
                    Object(5, 13, "Register", "buy stuff here"),
                    Object(36, 43, "table", "is a table wow")};

Person Workers[] = {Person(5, 13, 100.00f, "JohnCash", "Is a casheer"),
                    Person(40, 40, 100.00f, "DanSales", "Is a Salesmen")};

Store store(50.00f, Inventory, 5);
Map map(Structs, 3, Workers, 2);


int main()
{
    map.setStore(store);

    std::thread main(&Map::run, std::ref(map));
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::thread printer(&Map::printInfo, std::ref(map));

    std::string x = "0";
    while (x == "0")
    {
        std::cin >> x;
        if (x == "q")
        {
            map.stopRunning();
        }
        else
        {
            x = "0";
            map.SpawnCustomer();
        }
    }
    main.join();
    printer.join();

    return 0;
}
