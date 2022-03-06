// #include <iostream>
#include "Array.hpp"

int main(){

    Array arr(10);
    arr.create();
    arr.display();
    
    std::cout << std::endl;
   
    std::boolalpha;
    std::cout << arr.isSorted() << std::endl;

    arr.negaposisorted();
    arr.display();

    return 0;
}