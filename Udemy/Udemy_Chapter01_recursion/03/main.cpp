#include <iostream>

void func(int n){

    if (n > 0){
        
        std::cout << n << std::endl;
        func(n - 1);
    }
    return;
}

void func1(int n){
    while(n > 0){
        std::cout << n << std::endl;
        n--;
    }

}


int main(){

    func(3);
    func1(3);
 
    return 0;
}