#include <iostream>

// Queue using linked list

class Node{
public:
    int data;
    Node *next;
};

class Queue{
private:
    Node *front;
    Node *rear;

public:
    Queue(){
        front = rear = nullptr;
    }

    ~Queue() {
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
    void Enqueue(int x){
        Node *temp = new Node;
        if (temp == nullptr)
            std::cout << "Queue is full" << std::endl;
        else{
            temp->data = x;
            temp->next = nullptr;
            if (front == nullptr){
                front = rear = temp;
            } else{
                rear->next = temp;
                rear = temp;
            }
        }        
    }


    int Dequeue(){
        Node *temp;
        int x {-1};

        if (front == nullptr){
            std::cout << "Queue is empty" << std::endl;
        } else{
            x = front->data;
            temp = front;
            front = front->next;

            delete temp;
        }
        return x;
    }


    void Display(){
        Node *p = front;

        while (p != nullptr){
            std::cout << p->data << "->";
            p = p->next;
        }
        std::cout << "\\0"<< std::endl;
    }



};


int main(){

    Queue myQLL;
    myQLL.Enqueue(1);
    myQLL.Enqueue(2);
    myQLL.Enqueue(3);
    myQLL.Enqueue(4);
    myQLL.Enqueue(5);
    myQLL.Dequeue();
    myQLL.Dequeue();
    myQLL.Display();

    return 0;
}