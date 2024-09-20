#include <iostream>

#include "OrderedArray.h"

int main()
{
    OrderedArray<int> orderedArray(true, 5);
    orderedArray.push(4);
    orderedArray.push(20);
    orderedArray.push(1337);
    orderedArray.push(20);

    orderedArray.push(42);
    orderedArray.push(1337);

    std::cout << "Elements: ";
    for (int i = 0; i < orderedArray.getSize(); i++) {
        std::cout << orderedArray[i] << " ";
    }
    std::cout << std::endl;
}