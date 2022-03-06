#include <iostream>
#include <chrono>

//duplicate using hash for unsorted

int main(){
    
    int array1[] {1,2,4,5,7,8,9,0,10};
    int sz = 2*sizeof(array1) / sizeof(int);
    int hashtable[sz] = {0};
    int k = 10;

    for (int i = 0; i < sz/2; ++i){
        if (hashtable[k - array1[i]] != 0){
            std::cout << array1[i] << " + " << k-array1[i] << " = " << k << std::endl;
         }
        hashtable[array1[i]]++;
    }

    
    return 0;
}