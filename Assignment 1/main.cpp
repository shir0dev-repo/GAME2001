#include <iostream>

#include "OrderedArray.h"
#include "UnorderedArray.h"

int main() {
#pragma region UnorderedArray Demo

    UnorderedArray<int> unorderedArray(1, 1); // size: 1, grow: 1, 
    unorderedArray.push(21); // size: 1, grow: 1
    unorderedArray.push(9);  // size: 2, grow: 2
    unorderedArray.push(10); // size: 3, grow: 4
    unorderedArray.push(21); 
    unorderedArray.push(42); // size: 5, grow: 8

    std::cout << std::endl << unorderedArray << std::endl;

    int index = unorderedArray.find(10); // returns 2
    unorderedArray.remove(index); // removes 10
    std::cout << std::endl;

    unorderedArray.pop(); // removes 42
    std::cout << std::endl;
    
    unorderedArray.push(1);

    std::cout << unorderedArray << std::endl;
#pragma endregion

#pragma region OrderedArrayDemo

    // creates new OrderedArray from unordered one. will remove 21
    OrderedArray<int> oa = unorderedArray.sort(false); // size: 3, grow: 8
    std::cout << std::endl << oa << std::endl;

    oa.push(25);
    oa.push(22);
    oa.push(26);
    oa.allowDuplicates(true); // duplicates are now allowed.
    oa.push(21);
    oa.push(21);
    oa.push(21); // size: 9, grow: 16
    oa.push(26); // size: 9, grow: 16
    
    std::cout << oa << std::endl;
    
    oa.allowDuplicates(false, true); // turns off duplicate data and removes any existing duplicates

    std::cout << std::endl << oa << std::endl;
#pragma endregion
}