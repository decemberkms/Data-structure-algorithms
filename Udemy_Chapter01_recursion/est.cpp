#include <iostream>

// void foo (int n, int sum) {

// int k = 0, j = 0;

// if (n == 0) return;

// k = n % 10;

// j = n/10;

// sum = sum + k;

// foo (j, sum);

// std::cout << k << std::endl;

// }

// int f (int &x, int c){

//     c = c - 1; 
//     if (c == 0) return 1; 

//     x = x + 1; 
//     return f(x,c) * x;
// }

int fun (int n) { 
    int x=1; 

    if (n == 1) 
        return x; 
    
    for (int k=1; k<n; ++k)
        x = x + fun(k) * fun(n - k); 
    return x; 
}

int main(){
    std::cout << fun(5);
    
    }