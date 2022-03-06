#include <iostream>
#include <string>

// iterative merge sort


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

void iMerageSort(int A[], int n){
    int pass ;

    for (pass = 2; pass <= n; pass *= 2){
        for (int i = 0; i + pass -1 < n; i += pass){
            int low  = i;
            int high = i + pass - 1;
            int mid = (low + high) / 2;
            MergeSingle(A, low, mid, high);
        }
    }
    if ((pass / 2) < n)
        MergeSingle(A, 0, (pass /2) - 1, n -1);

}


int main(){
    int A[] = {11, 13, 7 ,12 ,16, 9, 24, 5, 10, 3, 14};
    int n = sizeof(A) / sizeof(int);

    iMerageSort(A, n);
    Print(A, n, "Array");

    return 0;
}