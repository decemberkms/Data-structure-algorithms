#include <iostream>
#include "DoubleLL.hpp"

int main(){
    int A[] = {9,2,3,4,5,6,7,8,1};

    DoublyLL Darray(A, sizeof(A) / sizeof(int));
    Darray.Display();


    std::cout << Darray.getMiddle() << std::endl;
    return 0;
}