#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Node.hpp"
#include <iostream>

// circular queue using array

class Queue{
public:
    int sizeq;
    int front;
    int rear;
    Node **Q;  // [Node*]* : pointer to [Pointer to node]

public:
    Queue(int size);
    ~Queue();

    bool isFull();    
    bool isEmpty();
    void Enqueue(Node *x);
    Node* Dequeue();
    void Display();

};


#endif