#include <iostream>


int main(){

    char A[] = "How are  you?";

    int i, vcount = 0;

    for (i = 0; A[i] != '\0'; ++i){
        if(A[i] == 'a'|| A[i] =='e'){
            vcount++;
        }
    }
    std::cout << vcount << std::endl;

    int word = 1;

    for (int i = 0; A[i] != '\0'; ++i){
        if (A[i] == ' ' && A[i - 1] != ' '){
            word++;
        }
    }

    std::cout << "Words: " << word << std::endl;

    return 0;
}