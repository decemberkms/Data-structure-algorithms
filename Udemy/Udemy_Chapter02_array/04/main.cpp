#include <iostream>
#include <iomanip>

// 2D array with three methods


int main(){

    // int array_1[3][4] { {1,2,3,4},
    //                     {2,4,6,8},
    //                     {3,5,7,9} };

    // for (int i = 0; i < 3; ++i){
    //     for (int j = 0; j < 4; ++j)
    //         std::cout << &array_1[i][j] << " ";
    //     std::cout << std::endl;
    // }

    // for (int i = 0; i < 12; ++i)
    //     std::cout << (array_1 + i) << std::endl;


    int *A[3]; // array of pointers
    A[0] = new int[4] {1, 2, 3, 4};
    A[1] = new int[4] {2, 4, 6, 8};
    A[2] = new int[4];
    A[2][0] = 15;


    for (int i = 0; i < 4; ++i)
        std::cout << A[0][i] << std::endl;
    
    std::cout << A[2][0] << std::endl;



    int **B; // pointer of pointers
    B = new int*[3];

    B[0] = new int[4];
    B[1] = new int [4];
    B[2] = new int [4];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            std::cout << B[i][j] << std::endl;
    
    return 0;
}