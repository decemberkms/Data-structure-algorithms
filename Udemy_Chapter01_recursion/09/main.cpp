#include <iostream>


int pow1(int m, int n){
    if (n == 0)
        return 1;
    return pow1(m, n - 1) * m;
}

int pow2(int m, int n){
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return pow2(m * m, n/2);
    else
        return m * pow2(m * m , (n - 1) / 2);
}

int pow3(int m, int n){
    int pow {1};

    for (int i = 1; i <= n; ++i){
        pow *= m;
    }
    
    return pow;
}

int main()
{

    std::cout << pow1(3, 10) << std::endl;
    std::cout << pow2(3, 10) << std::endl;
    std::cout << pow3(3, 10) << std::endl;

    return 0;
}