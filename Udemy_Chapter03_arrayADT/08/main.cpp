#include <iostream>
#include <chrono>

//duplicate using hash for unsorted

int main(){
    std::chrono::steady_clock sc;
    

    // int array1[] {3,6,4,6,7,8,9,6,4,2,3,6,7,5,4,2,5,3,8,9,6,5,3,2,3,4,6,7,8,8,6,5,4,3,12,4,5,54,3,2,5,12,12,2,3,1,13,5,3,2,1,1,2,1,2,3,4,1,2,3,5,4,3,1,2,4,6,4,3,2,3,5,6,4,2,2,3,2,5,4,7,8,9,0,8,7,6,5,3,2,4,5,2};
    // int array1[] {5,4,1,2,3,6,2,1,3,6,8,1,2,4,2,4};
    int array1[500000] {0,1,2,3,1,5,8,5,3,2,1,2,1,8,6,4,2,1,1,6,8,6,4,3,3,5,7,5,8,6,4,2,1,2};
    int sz = 2*sizeof(array1) / sizeof(int);
    int hashtable[sz] = {0};

    auto start = sc.now();
    for (int i = 0; i < sz/2; ++i){
        hashtable[array1[i]]++;
    }

    for (int i = 0; i < sz; ++i){
        if (hashtable[i] > 1){
            std::cout << "Duplicates: " << i << " " << hashtable[i] << std::endl;
        }
    }
    auto end = sc.now();
    auto time_span = static_cast<std::chrono::duration<double>>(end - start);
    std::cout << "hash time: " << 10000*time_span.count() << std::endl;

    auto start2 = sc.now();
    for (int i = 0; i < (sz/2) -1; ++i){    
        int count = 1;
        if (array1[i] != -1){
            for(int j = i + 1; j < (sz/2); ++j){
                if (array1[i] == array1[j]){
                    count++;
                    array1[j] = -1;
                }
            }
            if (count > 1) 
                std::cout << "Duplicate: " << array1[i] << " " << count << std::endl; 
        }

    }
    auto end2 = sc.now();
    auto time_span2 = static_cast<std::chrono::duration<double>>(end2 - start2);
    std::cout << "time: " << 10000*time_span2.count() << std::endl;
    
    return 0;
}