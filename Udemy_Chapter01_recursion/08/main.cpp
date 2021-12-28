#include <iostream>

// factorial of a number

int factorial1(int n){
    if (n <= 1)
        return 1;
    return factorial1(n - 1) * n;
}

int factorial2(int n){
    int i, s = 1;

    for (i = 1; i <= n; ++i){
        s *= i;
    }
    return s;
}

int main(){

    std::cout << factorial1(10) << std::endl;
    std::cout << factorial2(10) << std::endl;

    return 0;
}