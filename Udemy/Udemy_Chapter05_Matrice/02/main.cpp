#include <iostream>
#include <iomanip>

// lower triangular matrix - row major  mapping

class lowerTrianguler{
private:
    int size;
    int *array;
public:
    lowerTrianguler(int size_val)
        :size{size_val}{
        array = new int[size * (size + 1) / 2];  // number of elemtns is okay.
    }

    lowerTrianguler(int size_val, bool au_val)
        :size{size_val}{
        
        array = new int[size * (size + 1) / 2];  // number of elements is okay.

        if (au_val == 1)
            for (int i = 0 ; i < size * (size + 1) / 2; ++i) // start from 0
                array[i] = i; // this is okay. just putting numbers into all the array elements
        else
            create();
    }

    ~lowerTrianguler(){
        delete [] array;
        std::cout << "Destoryed" << std::endl;
    }
    
    void create(){
        for (int i = 0; i < size; ++i){
            std::cout << "Type element: " << i << std::endl;
            std::cin >> array[i];
        }
    }

    void Set(int i, int j, int k){
        if (i >= j)
            // array[(i*(i-1)/2) + (j - 1)] = k; // row major
            array[size * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)] = k; // column major
        else
            std::cout << "cannot set the value" << std::endl;

    }

    int Get(int i, int j){
        if (i >= j)
            // return array[(i*(i-1)/2) + (j - 1)]; // row major
            return array[size * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)]; // column major
        else
            return 0;

    }

     void display(){
        std::cout << "Elements: " << std::endl;
        for (int i = 1; i <= size; ++i)
        {
            for (int j = 1; j <= size; ++j)
            {
                if (i >= j) 
                    // std::cout << std::setw(3) << "[" << array[(i*(i-1)/2) + (j - 1)] << "]"; // due to negative values, you must use int i, j = 1
                    std::cout << std::setw(3) << "[" << array[size * (j - 1) - (j - 2) * (j - 1) / 2 + (i - j)] << "]"; 
                else 
                    std::cout << std::setw(3) << "[" << 0 << "]";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

};


int main(){ 

    lowerTrianguler myarr1(4, true);
    myarr1.display();
    myarr1.Set(3,2,1);
    myarr1.display();
    return 0;
}