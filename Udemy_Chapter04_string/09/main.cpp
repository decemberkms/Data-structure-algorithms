#include <iostream>
#include <bitset>


int main(){

    char A[] = "kimminsung";
    int H = 0, x = 0; 

    std::cout << "Size of long int: " << sizeof(int) << std::endl;

    for (int i = 0; A[i] != '\0'; ++i){
        x = 1;
        std::cout <<  std::bitset<32>(x) << std::endl; // bitset anonymous class
        x = x << (A[i] - 97);
        std::cout <<  std::bitset<32>(x) << std::endl; // bitset anonymous class
        

        if (x & H){  // masking (and)
            std::cout << "Duplicate: " << A[i] << std::endl;
        } else{
            H = x | H; // merging (or)
            std::cout <<  std::bitset<32>(H) << std::endl; // bitset anonymous class
        }

    }

    return 0;
}