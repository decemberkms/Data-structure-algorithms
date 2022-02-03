#include "QueueCpp.hpp"

Queue::Queue(int size)
        :sizeq{size}{
            Q = new Node* [size];
            front = rear = 0;
        }

Queue::~Queue(){
        delete [] Q;
    }

bool Queue::isFull(){
    if (rear == sizeq - 1)
        return true;
    return false;
}

bool Queue::isEmpty(){
    return front == rear;
}

void Queue::Enqueue(Node *x){
    if(isFull())
        std::cout << "Queue is full" << std::endl;
    else{
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::Dequeue(){
    Node* x = nullptr;

    if (isEmpty())
        std::cout << "Queue is empty" << std::endl;
    else{
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::Display(){
    int i = front + 1;
    do {
        std::cout << Q[i] << std::flush;
        if (i < rear){
            std::cout << " <- " << std::flush;
        }
        i = (i + 1) % sizeq;
    } while (i != (rear + 1) % sizeq);
}