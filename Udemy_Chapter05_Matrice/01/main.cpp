#include <iostream>
#include <iomanip>

// diagonal matrix

class Diagonal{
private:
    int size;
    int *array = new int[size];

public:
    Diagonal(int size_val)
        :size{size_val}{
    }
    Diagonal(int size_val, bool au_val)
        :size{size_val}{
            if (au_val == 1)
                for (int i = 0 ; i < size; ++i)
                    array[i] = i;
            else
                create();
    }

    ~Diagonal(){
        delete [] array;
        std::cout << "Destoryed" << std::endl;
    }

    void create(){
        for (int i = 0; i < size; ++i){
            std::cout << "Type element: " << i << std::endl;
            std::cin >> array[i];
        }
    }
    
    void display(){
        std::cout << "Elements: " << std::endl;
        for (int i = 0; i < size; ++i){
            for (int j = 0; j < size; ++j){
                if (i == j) std::cout << std::setw(3) << "[" << array[i] << "]";
                else std::cout << std::setw(3) << "[" << 0 << "]";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void Set(int i, int j, int x){
        if (i == j){
            array[i - 1] = x;
        } else{
            std::cout << "Wrong " << std::endl;
        }
    }

    int get(int i, int j){
        if (i == j)
            return array[i - 1];
        else 
            return 0;
    }

};


int main(){
    Diagonal myarr1(10, true);
    // myarr1.create();

    myarr1.Set(1,1,100); // here you don't use 0 position, it's real math here.
    myarr1.display();
    std::cout << myarr1.get(1,3) << std::endl;


    return 0;
}