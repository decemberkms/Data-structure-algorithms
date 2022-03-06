#include <iostream>
#include "DoubleLL.hpp"

int main(){
    int A[] = {9,2,3,4,5,6,7,8};

    DoublyLL Darray(A, sizeof(A) / sizeof(int));
    std::cout << Darray.Count() << std::endl;     
    Darray.Display();
    Darray.Insert(8, 10);
    Darray.Display();
    Darray.Insert(5, 20);
    Darray.Display();
    
    return 0;
}