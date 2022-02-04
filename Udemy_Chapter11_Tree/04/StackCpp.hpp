#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>

class NodeStack{
public:
    int data;
    NodeStack *next;
};


class LLStack{
private:
    NodeStack *bottom, *top;
public:
    LLStack();
    void Insert(int x);
    int Pop();
    int isFUll();
    int isEmpty();
    int Peek(int index);
    void Display();
};
#endif



