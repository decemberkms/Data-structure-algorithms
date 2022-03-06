#include <iostream>
#include <math.h>

class Node{
public:
    int coeff;
    int exp;
    Node *next;
};


class Polynomial{
private:
    Node *first;
    
public:
    Polynomial(int coefficient[], int exponential[], int sizeA){
        Node *temp, *last;
        first = new Node;
        
        first->coeff = coefficient[0];
        first->exp = exponential[0];
        first->next = nullptr;

        last = first;

        for (int i = 1; i < sizeA; ++i){
            temp = new Node;
            
            temp->coeff = coefficient[i];
            temp->exp = exponential[i];
            temp->next = nullptr;

            last->next = temp;
            last = temp;
        }
        temp = nullptr;
    }

    void Display(){
        Node *p = first;

        while(p){
            std::cout << p->coeff << "x" << "**" << p->exp << " + ";
            p = p->next;
        }
    }

    int eval(int x){
        int sum = 0;

        Node *p = first;

        while (p){
            sum += p->coeff*std::pow(x,p->exp);
            p = p->next;
        }
        
        return sum;
    }

};




int main() {
    int coefficient[] = {2,4,6};
    int exponential[] = {3,2,1};

    int sizeA = sizeof(coefficient) / sizeof(int);

    Polynomial myexx(coefficient, exponential, sizeA);
    myexx.Display();
    std::cout <<std::endl;

    std::cout << 3 << ":" << myexx.eval(2) << std::endl;


    return 0;
}