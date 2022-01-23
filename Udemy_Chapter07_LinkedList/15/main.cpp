#include <iostream>
#include "LinkedList.hpp"
#include "ClinkedList.hpp"

int main(){
    int A[] = {1,2,3,5,6,7,8,9,11,23};
    ClinkList Carray(A, sizeof(A)/sizeof(int));
    Carray.Display();
    std::cout << "\nArray Size" << Carray.Count() << std::endl;
    std::cout << Carray.Delete(11) << std::endl;
    Carray.Display();
    
    return 0;
}
    