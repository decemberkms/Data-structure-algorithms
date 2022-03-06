#include <iostream>

int main(){
    int Z[5];
    int A[5] {2,4,6,8,10};
    int B[5] {2,4};
    int C[] {2,4,6,8,10};
    int D[5] {1};
    
    std::cout << A[2] << std::endl;
    std::cout << 2[A] << std::endl;
    std::cout << *(A + 2) << std::endl;

    return 0;
}