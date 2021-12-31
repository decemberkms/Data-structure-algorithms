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

    arr.e_delete(1);
    arr.display();
    return 0;
}