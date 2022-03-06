#include <iostream>
#include <bitset>

//anagram

bool anagram1(char A[], char B[]){
    int a[26] {0};

    for (int i = 0; A[i] != '\0'; ++i){
        a[A[i] - 97] += 1;
    }

    for (int i = 0; B[i] != '\0'; ++i){
        a[B[i] - 97] -= 1;
        if (a[B[i] - 97] < 0){
            std::cout << "Not Anagram" << std::endl;
            return 0;
        }
    }
    std::cout << "Anagram" << std::endl;
    return 1;
}

bool anagram2(char A[], char B[]){
    int H {0}, Z {0};
    int x;

    for (int i = 0; A[i] != '\0'; ++i){
        x = 1;
        x = x << (A[i]- 97);
        std::cout << std::bitset<32>(x) << std::endl;
        H = H | x;
    }

    std::cout << "H: " << std::bitset<32>(H) << std::endl;

    for (int i = 0; B[i] != '\0'; ++i){
        x = 1;
        x = x << (B[i] - 97);
        std::cout << std::bitset<32>(x) << std::endl;
        Z = Z | x ;
    }
    std::cout << "Z: " << std::bitset<32>(Z) << std::endl;

    if (H == Z) 
        return 1;
    else
        return 0;
}

int main(){
    char A[] = "decimal";
    char B[] = "medical";


    std::cout << "Anagram? " << anagram1(A, B) << std::endl;
    std::cout << std::endl;
    
    std::cout << std::boolalpha << anagram2(A, B) << std::endl;




    

    return 0;
}