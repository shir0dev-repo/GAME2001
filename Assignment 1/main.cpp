#include <iostream>

#include "OrderedArray.h"
#include "UnorderedArray.h"

int main() {
#pragma region UnorderedArray Demo
    std::cout << "UNORDERED: " << std::endl << std::endl;

    UnorderedArray<int> unorderedArray(1, 1); // size: 1, grow: 1, 
    unorderedArray.push(21); // size: 1, grow: 1
    unorderedArray.push(9);  // size: 2, grow: 2
    unorderedArray.push(10); // size: 3, grow: 4
    unorderedArray.push(21); 
    unorderedArray.push(42); // size: 5, grow: 8

    std::cout << unorderedArray << std::endl;

    int index = unorderedArray.find(10); // returns 2
    unorderedArray.remove(index); // removes 10
    unorderedArray.pop(); // removes 42
    unorderedArray.push(1);

    std::cout << unorderedArray << std::endl << std::endl;
#pragma endregion

#pragma region OrderedArrayDemo
    std::cout << "Ordered: " << std::endl;

    // creates new OrderedArray from unordered one. will remove 21
    OrderedArray<int> oa = unorderedArray.sort(false); // size: 3, grow: 8
    std::cout << oa << std::endl;

    oa.push(25);
    oa.push(22);
    oa.push(26);
    oa.allowDuplicates(true); // duplicates are now allowed.
    oa.push(21);
    oa.push(21);
    
    std::cout << oa << std::endl;
    
    oa.allowDuplicates(false, true); // turns off duplicate data and removes any existing duplicates

    std::cout << oa << std::endl; 
#pragma endregion
}