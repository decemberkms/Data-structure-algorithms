#include <iostream>

//sum of natural numbers

int sum1(int n){
    if (n == 0)
        return 0;
    else
        return sum1(n -1) + n;
}

int sum2(int n){
    return n*(n+1)/2;
}

int sum3(int n)
{
    int i, s =0;
    for (i = 1; i <= n; i++){
        s = s + i;
    }
    return s;
}


int main(){

    std::cout << sum1(10) << std::endl;
    std::cout << sum2(10) << std::endl;
    std::cout << sum3(10) << std::endl;
    return 0;
}