#include <iostream>


//combination formula
int C(int n, int r){
    if (r == 0 || n == r)
        return 1;
    return C(n-1, r-1) + C(n-1, r);
}

int main(){

    std::cout << C(3,2) << std::endl;

    return 0;
}