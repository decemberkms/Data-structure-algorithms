#ifndef DoubleLL_H
#define DoubleLL_H

#include "Node.hpp"
#include <iostream>

class DoublyLL {
private:
    Node *first;
public:
    DoublyLL() {first = nullptr;}
    DoublyLL(int A[], int n);
    ~DoublyLL();
    int Count();
    void Insert(int index, int x);
    int Delete(int index);
    void Reverse();
    void Display();
}; 

#endif