#include <iostream>

// queue using array
class Queue{
public:
    int sizeq;
    int front;
    int rear;
    int * Q;
public:
    Queue(int size)
        :sizeq{size}{
        this->Q = new int[this->sizeq];
        this->front = this->rear = -1;
    }
    
    ~Queue(){
        delete [] Q;
    }

    void Enqueue(int x){     
        if ( this->rear == this->sizeq -1){
            std::cout << "Queue is full" << std::endl;
        } else {
            this->rear++;
            this->Q[this->rear] = x;             
        }
    }

    int Dequeue(){
        int x {-1};
        if (this->rear == this->front){
            std::cout << "No elements in the queue" << std::endl;
        } else{
            this->front++;
            x = this->Q[this->front];
        }
        return x;
    }


    void Display(){
        for (int i = front + 1; i < rear + 1; ++i){
            std::cout << Q[i] << std::endl;
        }
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