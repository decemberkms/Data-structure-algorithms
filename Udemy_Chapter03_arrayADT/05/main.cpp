// #include <iostream>
#include "Array.hpp"

int main(){

    Array arr(10,5);
    arr.create();
    arr.display();
    arr.size;
    Array arr2(10, 5);
    arr2.create();
    arr.display();
    

    Array arr3 = arr.mergeArrays(arr2, 20);

    std::cout << "\nCombined array" << std::endl;
    arr3.display();
    
    return 0;
}