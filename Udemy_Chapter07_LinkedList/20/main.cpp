#include <iostream>
#include "DoubleLL.hpp"

int main(){
    int A[] = {9,2,3,4,5,6,7,8};

    DoublyLL Darray(A, sizeof(A) / sizeof(int));
    Darray.Display();
    Darray.Reverse();
    Darray.Display();


    return 0;
}