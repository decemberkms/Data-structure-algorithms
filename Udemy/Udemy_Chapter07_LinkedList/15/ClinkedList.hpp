#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H
#include <iostream>
#include "Node.hpp"
// class Node {
// public:
//     int data;
//     Node *next;
// };

class ClinkList{
private:
    Node *head;

public:
    ClinkList(int A[], int n);
    ~ClinkList();
    void Display();
    void recursiveDisplay(Node *p);
    void Insert(int index, int x);
    int Delete(int index);
    int Count();
    Node* getHead(){return head;}

    
};


#endif