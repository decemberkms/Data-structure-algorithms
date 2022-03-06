#include <iostream>


// Tower of Hanoi
void TOH (int n, int A, int B, int C){
    if (n > 0){
        TOH(n - 1, A, C, B);
        std::cout << "From " << A << " to " << C << std::endl;
        TOH(n - 1, B, A, C);
    }
    return;
}


int main(){
    TOH(3,1,2,3);
    return 0;
}