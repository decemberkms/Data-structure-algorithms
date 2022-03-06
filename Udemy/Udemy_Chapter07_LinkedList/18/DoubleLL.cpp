#include "DoubleLL.hpp"

DoublyLL::DoublyLL(int A[], int n){
    Node *last, *temp;
    
    first = new Node;

    first->data = A[0];
    first->prev = nullptr;
    first->next = nullptr;
    
    last = first;

    for (int i = 1; i < n; ++i){
        temp = new Node;

        temp->data = A[i];
        temp->next = nullptr;
        temp->prev = last;

        last->next = temp;
        last = temp;            
    }                

}

int DoublyLL::Count(){
    Node *p = first;
    int count {0};

    while(p){
        count++;
        p = p->next;    
    }   
    return count;
}

void DoublyLL::Display(){
    Node *p = first;

    while (p != nullptr){
        std::cout << p->data << "->";
        p = p->next;
    }
    std::cout << "\\0" << std::endl;
}

void DoublyLL::Insert(int index, int x){
    Node *p = first;

    if (index < 0 || index > Count()){
        std::cout << "Program termination" << std::endl;
        std::exit(1);
    }
    Node *temp = new Node;
    
    if (index == 0){
        temp->data = x;
        temp->prev = nullptr;
        temp->next = first;

        first->prev = temp;
        first = temp;        
    } else{
        temp->data = x;
        for (int i = 0; i < index - 1; ++i){
            p = p->next;
        }
        temp->next = p->next;
        temp->prev = p;
    
        if (p->next)
            p->next->prev = temp;
    
        p->next = temp;
    }
}

int DoublyLL::Delete(int index){
    Node *p = first;
    int x;

    if (index < 0 || index > Count()){
        std::cout << "Program termination" << std::endl;
        std::exit(1);
    }

    
    if (index == 1){
        p = first;
        first = first->next;
        x = first->data;
        delete p;
        if (first)
            first->prev = nullptr;

    } else{
        p = first;
        for (int i = 0 ; i < index - 1; ++i){
            p = p->next;
        }

        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        x = p->data;
        delete p;
    }
    return x;
}