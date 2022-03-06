#include <iostream>



int main(){
    int array1[] {1,3,4,5,6,8,9,10,12,14};
    int sz = sizeof(array1)/sizeof(int);
    int k = 10;

    int i = 0, j =  sz - 1;
    // while (i < j){
    for (i,j;i<j;){
        if (array1[i] + array1[j] == k){
            std::cout << array1[i] << " " << array1[j] << " " << k << std::endl;
            i++;
            j--;
        } else if (array1[i] + array1[j] < k){
            i++;
        } else {
            j--;
        }
    }

    return 0;
}