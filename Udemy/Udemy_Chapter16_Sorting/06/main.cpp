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

void Merge(int A[], int B[], int m, int n, int C[]){
    int i, j, k;
    i = j = k = 0;
    
    while (i < m && j < n){
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    for (; i < m; ++i)
        C[k++] = A[i];
    for (; j < n ;++j)
        C[k++] = B[j];
}


void MergeSingle(int A[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];

    while (i <= mid && j <= high){
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }

    for (int i = low; i <= high; i++){ // copy all elements to A;
        A[i] = B[i];
    }
}


int main(){
    int A[] = {2, 10, 18, 20, 23};
    int n_A = sizeof(A) / sizeof(int);
    int B[] = {4, 9, 19, 25};
    int n_B = sizeof(B) / sizeof(int);
    int C[9];

    Merge(A, B, n_A, n_B, C);

    Print(C, 9, "New array: ");


    int D[] = {2, 5, 8, 12, 3, 6, 7 ,10};

    MergeSingle(D, 0, 3, 7);
    Print(D, 7, "New array: ");



    return 0;
}