#include <iostream>


//sparse matrix

// single elements
// we need an array of elements
class Element{
public:
    int x; // x coordinate
    int y;  // y coordinate
    int value; // value

public:
    // Element(){        
    // }
    // Element(int x_val, int y_val, int value_val)
    //     :x{x_val}, y{y_val}, value{value_val}{
    // }
};

class Sparse{
friend std::istream & operator>>(std::istream &is, Sparse &source); // this must be friend
friend std::ostream & operator<<(std::ostream &os, Sparse &source); // it would be weird to use it as member func.
    
public:
    int m;  // dimension m  -zero
    int n;  // dimension n - zero
    int num;  // number of non-zero elements - zero
    Element *e;

public:
    
    Sparse(){
    }
    //copy constructor
    // Sparse() 
    //     :Sparse(0, 0, 0){
    //         delete [] e;
    // }
    
    Sparse(int m_val, int n_val, int num_val)
        :m{m_val}, n{n_val}, num{num_val} {           
            e = new Element[this->num];
    }

    ~Sparse(){
        delete [] e;
    }

    Sparse operator+ (Sparse &s);    
};


Sparse Sparse::operator+ (Sparse &s){
    int i,j,k;
    if (this->m != s.m || this->n != s.n)
        return Sparse(0,0,0);

    Sparse *sum = new Sparse(m, n, this->num + s.num);

    i = j = k = 0;
    while (i < this->num && j < s.num){
        if (this->e[i].x < s.e[j].x)
            sum->e[k++] = this->e[i++];
        else if (this->e[i].x > s.e[j].x)
            sum->e[k++] = s.e[j++];
        else{
            if (this->e[i].y < s.e[j].y)
                sum->e[k++] = this->e[i++];
            else if (this->e[i].y > s.e[j].y)
                sum->e[k++] = s.e[j++];
            else {
                sum->e[k] = this->e[i];
                sum->e[k++].value = this->e[i++].value + s.e[j++].value;
            }
        }
    }

    for (; i < this->num; ++i) sum->e[k++] = this->e[i];
    for (; j < s.num; ++j) sum->e[k++] = s.e[j];
    sum->num = k;

    return *sum;
}


std::istream & operator>>(std::istream &is, Sparse &source){
    std::cout << "Enter all the elements three values with whitespace\n";

    for (int i = 0; i < source.num; ++i){
        std::cin >> source.e[i].x >> source.e[i].y >> source.e[i].value;
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, Sparse &source){
    int k = 0;

    for (int i = 0; i < source.m; ++i){
        for (int j = 0; j < source.n; ++j){
            if (i == source.e[k].x && j == source.e[k].y)
                std::cout << source.e[k++].value << " ";
            else 
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }
    return os;
}

int main(){
    Sparse s1(3,3,3);
    Sparse s2(3,3,3);
    
    std::cin >> s1;
    std::cout << s1;
    std::cout << std::endl;
    std::cin >> s2;
    std::cout << s2;

    std::cout << std::endl;
    
    Sparse s3 = s1 + s2;
    std::cout << s3;

    return 0;
}