#include "Array.hpp"

//constructor
Array::Array(int size){
    this->size = size;
    length = 0;
    A = new int[size];
}

Array::Array(int size, int length){
    this->size = size;
    this->length = length;
    A = new int[size];
}

Array::Array(int size, int length, int elements[]){
    this->size = size;
    this->length = length;
    A = new int[size];

    for (int i = 0; i < length; ++i){
        A[i] = elements[i];
    }

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
    if (this->length==0){
        std::cout << "Enter number of elements: " << std::flush;
        std::cin >> length;
        
    }
    
    std::cout << "Enter the array elements: " << std::endl;
    for (int i = 0; i < length; ++i){
        std::cout << "Array element: " << i << " = " << std::flush;
        std::cin >> A[i];
    }
}

void Array::append(int x){  
    if (this->length < this->size){
        this->A[this->length] = x;
        this->length++;
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

int Array::Delete(int index){
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

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int Array::linearSearch(int key){
    for (int i = 0; i < this->length; ++i)
        if (this->A[i] == key)
            return i;
    return -1;
}

int Array::binarySearch_loop(int low, int high, int key){
    while (low <= high){
        int mid = (low + high) / 2;
        if (key == A[mid])
            return mid;
        else if (key > A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Array::binarySearch_recursive(int low, int high, int key){
    if (low <= high){
        int mid = (low + high) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return binarySearch_recursive(low, mid - 1, key);
        else
            return binarySearch_recursive(mid + 1, high, key);
    }
    return -1;
}

int Array::Get(int index){
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array::Set(int index, int x){
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::Max(){
    int max = A[0];
    for (int i = 0; i < length; ++i){
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for (int i = 0; i < length; ++i){
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum(){
    int total = 0;
    for (int i = 0; i < length; ++i)
        total += A[i];
    
    return total;
}

int Array::Average(){
    return Array::Sum()/length;
}

void Array::Reverse(){
    for (int i = 0, j = length - 1; i < j; i++, j--){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

void Array::insert2(int x){
    int i = length - 1;
    while (A[i] > x){
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++; 
}

bool Array::isSorted(){
    for (int i = 0; i < length - 1; ++i){
        if (A[i] > A[i + 1])
            return false;
    }   
    return 1;
}

void Array::negaposisorted(){
    int i = 0;
    int j = length - 1;
    while(i < j){
        while(A[i] < 0) {i++;}
        while(A[j] >= 0) {j--;}
        if (i < j){
            int temp;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}

Array Array::mergeArrays(Array& arr, int size_combined){
    Array C(size_combined, length + arr.length);
    int i = 0, j = 0, k = 0;
    
    while (i < this->length && j < arr.length){
        if (this->A[i] < arr.A[j])
            C.A[k++] = this->A[i++];
        else
            C.A[k++] = arr.A[j++];
    }   

    for (;i < this->length; ++i)
        C.A[k++] = this->A[i];
    for (;j < arr.length; ++j) 
        C.A[k++] = arr.A[j];

    C.length = k;

    return C;
}

Array Array::UnionArrays(Array &arr){
    Array C(this->size + arr.size, this->length + arr.length);
    int i = 0, j = 0, k = 0;
    
    while (i < this->length && j < arr.length){
        if (this->A[i] < arr.A[j]){
            C.A[k++] = this->A[i++];
        } else if (arr.A[j] < this->A[i]){
            C.A[k++] = arr.A[j++];
        } else{
            C.A[k++] = this->A[i++];
            j++;
        }
    }   

    for (;i < this->length; ++i)
        C.A[k++] = this->A[i];
    for (;j < arr.length; ++j) 
        C.A[k++] = arr.A[j];

    C.length = k;

    return C;
}

Array Array::Intersection(Array &arr){
   Array C(this->size, this->length);
    int i = 0, j = 0, k = 0;
    
    while (i < this->length && j < arr.length){
        if (this->A[i] < arr.A[j]){
            i++;
        } else if (arr.A[j] < this->A[i]){
            j++;
        } else{
            C.A[k++] = this->A[i++];
            j++;
        }
    }   

    C.length = k;

    return C;
}

Array Array::Difference(Array &arr){
    Array C(this->size + arr.size, this->length + arr.length);
    int i = 0, j = 0, k = 0;
    
    while (i < this->length && j < arr.length){
        if (this->A[i] < arr.A[j]){
            C.A[k++] = this->A[i++];
        } else if (arr.A[j] < this->A[i]){
            j++;
        } else{
            i++;
            j++;
        }
    }   

    for (;i < this->length; ++i)
        C.A[k++] = this->A[i];

    C.length = k;

    return C;
}