#include <iostream>
#include <bitset>

void perm(char s[], int k){
    static int A[10] = {0};
    static char Res[10];
    
    // static int z {0};
    
    if (s[k] == '\0'){
        Res[k] = '\0';
        // z++;
        std::cout << Res << std::endl;
        // std::coxcut << z << std::endl;
    }
    else{
        for (int i = 0; s[i] != '\0'; ++i){
            if (A[i] == 0){
                Res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

void perm2(char s[], int k){
    static int A[10] = {0};
    static char Res[10];
    static short int B {1};
    
    // static int z {0};
    
    if (s[k] == '\0'){
        Res[k] = '\0';
        std::cout << Res << std::endl;
    }
    else{
        for (int i = 0; s[i] != '\0'; ++i){
            if (A[i] == 0){
                Res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main(){
    char s[] = "ABC";
    perm(s, 0);


    return 0;
}