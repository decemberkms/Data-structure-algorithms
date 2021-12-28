#include <iostream>

void func(int n){

    if (n > 0){
        
        std::cout << n << std::endl;
        func(n - 1);
        func(n - 1);
    }
    return;
}




int main(){

    func(3);

 
    return 0;
}