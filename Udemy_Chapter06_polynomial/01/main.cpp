#include <iostream>
#include <math.h>

class Term{
public:
    int coeff;
    int exp;
};

class Poly{
friend std::istream & operator>>(std::istream &is, Poly &source); 
friend std::ostream & operator<<(std::ostream &os, Poly &source); 
private:
    int n;// how many termns
    Term *terms;
public:
    Poly(int n_val)
        :n{n_val}{
            terms = new Term[n];
    }
    

};

std::istream & operator>>(std::istream &is, Poly &source){
    std::cout << "Enter term and coeiff\n";

    for (int i = 0; i < source.n; ++i){
        std::cin >> source.terms[i].coeff >> source.terms[i].exp;
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, Poly &source){
    int k = 0;

    for (int i = 0; i < source.n; ++i){
        std::cout << source.terms[i].coeff << "*";
        std::cout << source.terms[i].exp << " ";
    }
    return os;
}


int main(){
    Poly px1(3);
    
    std::cin >> px1;
    std::cout << px1;

    return 0;
}