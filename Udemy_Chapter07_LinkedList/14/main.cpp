#include <iostream>
#include "LinkedList.hpp"
#include "ClinkedList.hpp"

int main(){
    int A[] = {1,2,3,5,6,7,8,9,11,23};
    // LinkedList array(A, sizeof(A)/sizeof(int));
    
    // array.Display();
    // array.Insert(3, 10);
    // array.Display();
    // array.Delete(0);
    // array.Display();
    
    std::cout << std::flush << std::endl;

    ClinkList Carray(A, sizeof(A)/sizeof(int));
    Carray.Display();
    Carray.Insert(0,10);
    Carray.Display();
    Carray.Insert(11,99);
    Carray.Display();

    
    
    return 0;
}
    