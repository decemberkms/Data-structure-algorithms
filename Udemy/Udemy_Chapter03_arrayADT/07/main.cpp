#include <iostream>

//duplicate using hash

int main(){
    int array1[] {3,6,8,8,10,12,15,15,15,20};
    int sz = 2*sizeof(array1) / sizeof(int);
    int hashtable[sz] = {0};

    for (int i = 0; i < sz/2; ++i){
        hashtable[array1[i]]++;
    }

    for (int i = 0; i < sz; ++i){
        if (hashtable[i] > 1){
            std::cout << "Duplicates: " << i << " " << hashtable[i] << std::endl;
        }
    }


    return 0;
}