#include "StackCpp.hpp"

LLStack::LLStack() {top = nullptr;}

void LLStack::Insert(int x){
        NodeStack *temp = new NodeStack;   
        if (temp == nullptr){
            std::cout << "Stack overflow" << std::endl;
        } else{    
             
            temp->data = x;
            temp->next = top;
            top = temp;
        }
    }

int LLStack::Pop(){
        int x {0};

        if (top == nullptr){
            std::cout << "Nothing to pop" << std::endl;
        } else{
            NodeStack *p = top;
            x = top->data;
            top = top->next;

            delete p;                            
        }
        return x;        
    }

 int LLStack::isFUll(){
        NodeStack *temp = new NodeStack;
        int r = temp ? 1: 0;
        delete temp;
        return r;
    }

int LLStack::isEmpty(){
        return top ?0:1;
    }


int LLStack::Peek(int index){
        int x = -1, i;
        NodeStack *p = top;
        
        for(i = 0; p != nullptr && i < index -1; ++i){
            p = p->next;
        }
        if (p != nullptr)
            return p->data;
        else 
            return -1;
    }

void LLStack::Display(){
        NodeStack *p = top;
        while (p !=nullptr){
            std::cout << p->data << "->";
            p = p->next;
        }
        std::cout << "\\0";
    }