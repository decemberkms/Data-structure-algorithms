#include <iostream>

int main(){

    unsigned int x[4][3]  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}; 

    std::cout << x + 3 << std::endl; // pointer value
    std::cout << *(x + 3) << std::endl; // array ~= pointer so it prints the address pointer's pointer
    std::cout << **(x + 3) << std::endl;// we need two deref because arrays has an array in it

    return 0;
}