#include <iostream>
#include <string>

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


void Selection(int A[], int n){
    for (int i = 0; i < n - 1; ++i){
        int j, k;
        for (j = k = i; j < n; ++j){
            if (A[j] < A[k]){
                k = j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }

}

int main(){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, "\tA");
 
    Selection(A, n);
    Print(A, n, " Sorted A");
 
 
    return 0;
}