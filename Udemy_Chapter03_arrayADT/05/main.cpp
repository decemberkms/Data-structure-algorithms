// #include <iostream>
#include "Array.hpp"

int main(){

    int TT[] = {1,2,3,4,5};
    Array arr(10, 5, TT);
    // Array arr(10, 5, {1,2,3,4,5});
    arr.display();
 
    int TT2[] = {3,4,5,6,7};
    Array arr2(10, 5, TT2);
    // arr2.create();
    arr2.display();
    
    Array arr3  = arr.UnionArrays(arr2);
    std::cout << "\n Union: " << std::endl;
    arr3.display();

    Array arr4 = arr.Intersection(arr2);
    std::cout << "\n Intersection: " << std::endl;
    arr4.display();
    
    Array arr5 = arr.Difference(arr2);
    std::cout << "\n Intersection: " << std::endl;
    arr5.display();
    

    
    return 0;
}