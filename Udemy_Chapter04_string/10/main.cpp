#include <iostream>


//anagram

int main(){
    char A[] = "verbose";
    char B[] = "observe";
    int a[26] {0};
    

    for (int i = 0; A[i] != '\0'; ++i){
        a[A[i] - 97] += 1;
    }

    for (int i = 0; B[i] != '\0'; ++i){
        a[B[i] - 97] -= 1;
        if (a[B[i] - 97] < 0){
            std::cout << "Not Anagram" << std::endl;
            break;
        }
    }
    std::cout << "Anagram" << std::endl;


    

    return 0;
}