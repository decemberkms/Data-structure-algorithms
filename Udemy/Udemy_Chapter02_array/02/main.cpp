#include <iostream>

int main(){

    // int n;
    
    // std::cout << "Type the size of array: ";
    // std::cin >> n;

    // int B[n];

    // std::cout << B[0];

    int *ptr;
    ptr = new int[5];

    for (int i = 0; i < 5; ++i){
        ptr[i] = i;        
    }

    for (int i =0; i < 5; ++i){
        std::cout << ptr[i] << std::endl;
    }
    

    delete [] ptr;

    return 0;
}