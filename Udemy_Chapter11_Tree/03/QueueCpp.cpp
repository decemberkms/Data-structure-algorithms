#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Node.cpp"
#include <iostream>

// circular queue using array

class Queue{
public:
    int sizeq;
    int front;
    int rear;
    Node **Q;  // [Node*]* : pointer to [Pointer to node]

public:
    Queue(int size)
        :sizeq{size}{
            Q = new Node* [size];
            front = rear = 0;
        }

    ~Queue(){
        delete [] Q;
    }

    bool isFull(){
        if (rear == sizeq - 1)
            return true;
        return false;
    }
    
    bool isEmpty(){
        return front == rear;
    }

    void Enqueue(Node *x){
        if(isFull())
            std::cout << "Queue is full" << std::endl;
        else{
            rear++;
            Q[rear] = x;
        }
    }

    Node* Dequeue(){
        Node* x = nullptr;

        if (isEmpty())
            std::cout << "Queue is empty" << std::endl;
        else{
            front++;
            x = Q[front];
        }
        return x;
    }
    
    void Display(){
        int i = front + 1;
        do {
            std::cout << Q[i] << std::flush;
            if (i < rear){
                std::cout << " <- " << std::flush;
            }
            i = (i + 1) % sizeq;
        } while (i != (rear + 1) % sizeq);
    }

};


#endif