#include <iostream>

// circular queue using array

class Queue{
public:
    int sizeq;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size)
        :sizeq{size}{
            Q = new int[size];
            front = rear = 0;
        }

    ~Queue(){
        delete [] Q;
    }

    void Enqueue(int x){
        if( ((rear + 1) % sizeq) == (front) )
            std::cout << "Queue is full" << std::endl;
        else{
            rear = (rear + 1) % sizeq;
            Q[rear] = x;
        }
    }

    int Dequeue(){
        int x = -1;

        if (front == rear)
            std::cout << "Queue is empty" << std::endl;
        else{
            front = (front + 1) % sizeq;
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



int main(){

    Queue myQ(10);
    myQ.Enqueue(1);
    myQ.Enqueue(2);
    myQ.Enqueue(3);
    myQ.Enqueue(4);
    myQ.Enqueue(5);
    myQ.Enqueue(6);
    myQ.Dequeue();
    myQ.Dequeue();
    myQ.Display();


    return 0;
}