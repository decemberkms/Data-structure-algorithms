#include <iostream>
#include <algorithm>
#include <iterator>

//Count Sort

template <class T>
void Print(T& vec, int n, std::string s){
    std::cout << s << ": [" << std::flush;
    for (int i=0; i<n; i++){
        std::cout << vec[i] << std::flush;
        if (i < n-1){
            std::cout << ", " << std::flush;
        }
    }
    std::cout << "]" << std::endl;
}

void CountSort(int A[], int n){
    int max = *std::max_element(A , A + n);
    int *C = new int[max + 1];
   
    for (int i = 0; i < max + 1; ++i)
        C[i] = 0;

    for (int i = 0; i < n; ++i)
        C[A[i]]++;
    
    int i = 0; 
    int j = 0;
    
    while (j < max + 1){
        if (C[j] > 0){
            A[i++] = j;
            C[j]--;
        }
        else
            ++j;            
    }

    delete [] C ;
}


int main(){
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(int);
    Print(A, n, "Array");

    CountSort(A, n);
    Print(A, n, "Array");
    

    return 0;
}