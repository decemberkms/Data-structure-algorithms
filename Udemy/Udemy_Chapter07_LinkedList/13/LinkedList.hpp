#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.hpp"
// class Node{
// public:
//     int data;
//     Node *next;
// };

class LinkedList{
private:
    Node *first;

public:
    LinkedList() {first = nullptr;}
    LinkedList(int A[], int n );
    ~LinkedList();

    void Display();
    bool Insert(int index, int x);
    int Delete(int index);
    int Count();
    int Sum();
};

#endif