#include <iostream>

void funcB(int n);

void funcA(int n)
{
    if(n > 0){
        std::cout << "FuncA: " << n << std::endl;
        funcB(n - 1);
    }

}

void funcB(int n){
    if(n > 0){
        std::cout << "FuncB: " << n << std::endl;
        funcA(n - 1);
    }

}

int main(){

    funcA(20);

    return 0;
}