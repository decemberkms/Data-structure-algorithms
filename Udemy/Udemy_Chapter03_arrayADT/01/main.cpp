// #include <iostream>
#include "Array.hpp"

int main(){

    Array arr(10);

    arr.create();
    arr.display();

    arr.append(6);
    arr.display();

    arr.insert(1, 100);
    arr.display();

    arr.Delete(1);
    arr.display();

    std::cout << "\nResult index: " << arr.linearSearch(6) << std::endl;
    std::cout << "Result index: " <<  arr.linearSearch(100) << std::endl;

    std::cout << "\nResult index: " << arr.binarySearch_loop(0,5,3) << std::endl;
    std::cout << "Result index: " <<  arr.binarySearch_recursive(0,5,8) << std::endl;
    return 0;
}