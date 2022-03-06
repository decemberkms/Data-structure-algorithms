#include <iostream>
#include <string>

using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h){

    int pivot = A[l];
    int i = l;
    int j = h;

    do {
        do {i++;} while (A[i] <= pivot);
        do {j--;} while (A[j] > pivot);

        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;

        }
    } while(i < j);

    int temp2 = A[j];
    A[j] = A[l];
    A[l] = temp2;

    return j;
}



int partitionA(int A[], int low, int high){
    int pivot = A[low];
    int i = low;
    int j = high;
 
    do {
        // Increment i as long as elements are smaller/equal to pivot
        do {i++;} while (A[i] <= pivot);
 
        // Decrement j as long as elements are larger than pivot
        do {j--;} while (A[j] > pivot);
 
        if (i < j){
            swap(&A[i], &A[j]);
        }
    } while (i < j);
 
    swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h){
    if (l < h){
        int j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j+ 1, h);
    }
}

int main(){

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767};
    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n-1, "\tA");

    QuickSort(A, 0, n-1);
    Print(A, n-1, " Sorted A");
    cout << endl;

    return 0;
}