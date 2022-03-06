#include <iostream>

int main(){

    int *ptr_1 = new int[5];

    for (int i = 0; i < 5; ++i)
        ptr_1[i] = i*i;

    for (int i = 0; i < 5; ++i)
        std::cout << ptr_1[i] << " ";

    std::cout << std::endl;

    int *ptr_2 = new int[10];

    for (int i = 0; i < 5; ++i){
        ptr_2[i] = ptr_1[i];
    }

    delete [] ptr_1;

    ptr_1 = ptr_2;

    ptr_2 = nullptr;

    ptr_1[5] = 25;

    for (int i = 0; i < 10; ++i)
        std::cout << ptr_1[i] << " ";


    

    return 0;
}