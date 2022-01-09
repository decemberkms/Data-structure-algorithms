#include <iostream>

// find missing elements

int main(){
    int array1[] {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int sz = 2*sizeof(array1) / sizeof(int);
    int hashtable[sz] = {0};

    for (int i = 0; i < sz/2; ++i){
        hashtable[array1[i]]++;
    }

    for (int i = 0; i < sz; ++i){
        if (hashtable[i] == 0){
            std::cout << "Missing: " << i << " " << std::endl;
        }
    }

    return 0;
}