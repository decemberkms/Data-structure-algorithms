#include <iostream>


void my_func(const int &n){

    if (n > 0){
    std::cout << n << " recursive Ascending calling" << std::endl;
    my_func(n - 1);
    std::cout << n << " recursive Descending returning" << std::endl;
    }
    return;
}


int main(){
    my_func(5);


    return 0;
}