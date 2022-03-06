#include <iostream>
#include <bitset>
#include <iomanip>

int main(){

    int x = 1;

    std::cout << x << ": \n"<<  std::bitset<32>(x) << std::endl;
    x = x << 1;
    std::cout << x << ": \n"<<  std::bitset<32>(x) << std::endl;
    x = x << 1;
    std::cout << x << ": \n"<<  std::bitset<32>(x) << std::endl;
    x = x << 1;
    std::cout << x << ": \n"<<  std::bitset<32>(x) << std::endl;
    x = x << 1;
    std::cout << x << ": \n"<<  std::bitset<32>(x) << std::endl;
    x = x << 1;
    std::cout << x << ": \n"<<  std::bitset<32>(x) << std::endl;

    return 0;
}