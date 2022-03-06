#include <iostream>

int main(){
    char A[] = "finding";
    int sz = sizeof(A) / sizeof(char);
    int B[26] ={0};


    for (int i = 0; A[i] != '\0'; ++i){
        
        B[A[i] - 97] += 1;
    }

    for (int i = 0; i < 25; ++i)
        
        std::cout << char(i+97) << ": " << B[i] << std::endl;


    return 0;
}