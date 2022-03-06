#include <iostream>

// stack using linkedlist

class Node{
public:
    int data;
    Node *next;
};


class LLStack{
private:
    Node *bottom, *top;
public:
    LLStack() {top = nullptr;}
    
    void Insert(int x){
        Node *temp = new Node;   
        if (temp == nullptr){
            std::cout << "Stack overflow" << std::endl;
        } else{    
             
            temp->data = x;
            temp->next = top;
            top = temp;
        }
    }

    int Pop(){
        int x {0};

        if (top == nullptr){
            std::cout << "Nothing to pop" << std::endl;
        } else{
            Node *p = top;
            x = top->data;
            top = top->next;

            delete p;                            
        }
        return x;        
    }

    int isFUll(){
        Node *temp = new Node;
        int r = temp ? 1: 0;
        delete temp;
        return r;
    }

    int isEmpty(){
        return top ?0:1;
    }
    

    int Peek(int index){
        int x = -1, i;
        Node *p = top;
        
        for(i = 0; p != nullptr && i < index -1; ++i){
            p = p->next;
        }
        if (p != nullptr)
            return p->data;
        else 
            return -1;
    }

    void Display(){
        Node *p = top;
        while (p !=nullptr){
            std::cout << p->data << "->";
            p = p->next;
        }
        std::cout << "\\0";
    }
};


int main(){
    LLStack myStack;

    myStack.Insert(10);
    myStack.Insert(20);
    std::cout << myStack.Pop() << std::endl;
    myStack.Insert(30);
    std::cout << myStack.Peek(0) << std::endl;
    myStack.Display();

    return 0;
}











