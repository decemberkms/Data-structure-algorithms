#include <iostream>

int func(int n)
{
    if(n > 5)
        return n - 1;
    else
        return func(func(n + 1));

}


int main(){

    std::cout << "Result: " <<  func(7) << std::endl;

    return 0;
}