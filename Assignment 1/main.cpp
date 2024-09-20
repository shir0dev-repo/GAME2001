#include <iostream>

#include "OrderedArray.h"

int main()
{
    OrderedArray<int> orderedArray(true, 1, 2);
    orderedArray.push(4);
    orderedArray.push(20);
    orderedArray.push(1337);
    orderedArray.push(20);

    orderedArray.push(42);
    orderedArray.push(73);
    orderedArray.push(21);
    orderedArray.push(1337);

    std::cout << orderedArray;

    // removes both 1337's
    orderedArray.pop();
    orderedArray.pop();

    // removes 73
    orderedArray.remove(5);

    std::cout << orderedArray;
    

 /*   std::cout << "Max: " << orderedArray.getMaxSize() << std::endl;
    std::cout << "Grow: " << orderedArray.getGrowSize() << std::endl;*/
}