#include <iostream>

using namespace std;

void Insert(int A[], int n){
    int i = n;
    int temp = A[n];

    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1: i / 2]){
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i /2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;    
}

void createHeap(int A[], int n){
    for (int i = 0; i < n; ++i){
        Insert(A, i);
    }
}


void Delete(int A[], int n){
    int x, i, j, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2*i;

    while(j <= n - 1){
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j]){
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i = j;
            j = 2*j;
        } else
            break;        
    }
    A[n] = x;
}

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Delete2(int A[], int n){
    int x = A[0];  // Max element
    int lastele = A[n - 1];
    A[n] = x;
    A[0] = lastele;
    
    int i = 0;
    int j = 2 * i + 1;
 
    while (j + 1 <= n-1){
        // Compare left and right children
        if (j < n - 1 && A[j] < A[j+1]){
            j = j+1;
        }
 
        // Compare parent and largest child
        if (A[i] < A[j]){
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    return x;
}


template <class T>
void Print(T& vec, int n, char s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}


int main(){
    std::cout << "Create Heap" << std::endl;

    int arr[] = {10,20,30,25,5,40,35};
    Print(arr, sizeof(arr) / sizeof(int), 'a');
    
    createHeap(arr, sizeof(arr) / sizeof(int));
    Print(arr, sizeof(arr) / sizeof(int), 'a');

    Delete2(arr, sizeof(arr) / sizeof(int));
    Print(arr, sizeof(arr) / sizeof(int), 'a');
    Delete2(arr, sizeof(arr) / sizeof(int));
    Delete2(arr, sizeof(arr) / sizeof(int));
    Print(arr, sizeof(arr) / sizeof(int), 'a');
    return 0;
}