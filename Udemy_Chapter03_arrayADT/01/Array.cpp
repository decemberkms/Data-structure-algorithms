#include "Array.hpp"

//constructor
Array::Array(int size){
    this->size = size;
    A = new int[size];
}

//destructor
Array::~Array(){
    delete [] A;
    std::cout << "\nArray has been destroyed" << std::endl;
}


void Array::display(){
    std::cout << "\nElements are\n";
    for (int i = 0; i < length; i++){
        std::cout << A[i] << " ";
    }
}

void Array::create(){
    std::cout << "Enter number of elements: " << std::flush;
    std::cin >> length;
    std::cout << "Enter the array elements: " << std::endl;
    for (int i = 0; i < length; ++i){
        std::cout << "Array element: " << i << " = " << std::flush;
        std::cin >> A[i];
    }
}

void Array::append(int x){  
    if (this->length < this->size){
        this->A[this->length++] = x;
    } else {
        std::cout << "Lengths has reached the maximum (Size)" << std::endl;
    }
}

void Array::insert(int index, int x){
    if (index >= 0 && index <= this->length){
        for (int i = this->length; i > index; --i)
            this->A[i] = this->A[i - 1];
        this->A[index] = x;
        this->length++;
    }
}

int Array::e_delete(int index){
    int x = 0;
    if (index >= 0 && index < this ->length){
        x = this->A[index];
        for (int i = index; i < this->length - 1; ++i)
            this->A[i] = this->A[i + 1];
        this->length--;
        return x;
    }
    return 0;
}