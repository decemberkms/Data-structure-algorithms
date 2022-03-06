#include <iostream>


int main(){

    char s[] = "welcome";
    char j[] = "String";
  
    for (int i = 0; s[i] != '\0';i++){
        s[i] -= 32;
    }
    std::cout << s << std::endl;


    char A[] = "wElCoMe";

    std::cout << A << std::endl;

    for (int i = 0; A[i] != '\0'; ++i){
        if (A[i]>= 65 && A[i] <= 90){
            A[i] += 32;
        } else if(A[i] >= 90 && A[i] <= 122) {
            A[i] -= 32;
        }
    }
    std::cout << A << std::endl;
    return 0;
}