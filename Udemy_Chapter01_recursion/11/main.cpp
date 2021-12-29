#include <iostream>

//Fibonacci series

int fibonacci1(int n){
    if (n <= 1)
        return n;
    else {
        return fibonacci1(n-2) + fibonacci1(n -1);
    }    
}

int fibonacci2(int n){
    int t0 = 0, t1 = 1 ,s;

    if (n <= 1) 
        return n;
    for(int i = 2; i <= n; ++i){
        s = t1 + t0;
        t0 = t1;
        t1 = s;
    }
    return s;

}

int F[10] {-1,-1,-1,-1,-1,-1, -1, -1, -1, -1};

int fibonacci3(int n){
    if (n <= 1){
        F[n] = n;
        return n;
    }
    else{
        if (F[n - 2] == -1){
            F[n - 2] = fibonacci3(n-2);
        }
        if (F[n - 1] == -1){
            F[n - 1] = fibonacci3(n-1);
        }
        return F[n - 2] + F[n - 1];
    }

}

int main(){

    std::cout << fibonacci1(10) << std::endl;
    std::cout << fibonacci2(10) << std::endl;
    std::cout << fibonacci3(10) << std::endl;
    return 0;
}