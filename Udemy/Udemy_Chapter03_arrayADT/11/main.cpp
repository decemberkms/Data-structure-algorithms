#include <iostream>

int main(){
    int array1[] {5,8,3,9,5,1,-1,23,20,1,3,9};
    int sz = sizeof(array1)/sizeof(int);
    int min = array1[0];
    int max = array1[0];

    for (int i = 0; i < sz; ++i){
        if (array1[i] < min)
            min = array1[i];
        else if (array1[i] > max)
            max = array1[i];
    }

    std::cout << min << " " << max << std::endl;

    return 0;
}