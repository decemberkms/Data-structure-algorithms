#include <iostream>

class Node{
public:
    int data;
    Node *next; // self deferential class
public:

};

void displayRe1(Node *p){
        if(p != nullptr){
            std::cout << p->data << std::endl;
            displayRe1(p->next);
        }
}

void displayRe2(Node *p){
        if(p != nullptr){
            displayRe2(p->next);
            std::cout << p->data << std::endl;
            
        }
}


int main(){

    int A[] = {3, 5, 7 , 10, 15};
    
    Node *head = new Node;

    Node *temp;
    Node *last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    for (int i = 1; i < sizeof(A)/sizeof(int); ++i){
        temp = new Node;

        temp->data = A[i];
        temp->next = nullptr;

        last->next = temp;
        last = temp;
        
        std::cout << "Address of temp: "<< temp << std::endl;
    }

    Node *p = head;
    
    while (p != nullptr){
        std::cout << p->data << " -> " << std::flush;
        p = p->next;
    }


    std::cout << std::endl;
    p = head;
    displayRe1(p);


    std::cout << std::endl;
    p = head;
    displayRe2(p);
    std::cout << std::endl;
    int *a;
    a = new int;
    std::cout << "\nAddress of a: "<< a << "\nPinter: " << &a << std::endl;
    a = new int;
    std::cout << "Address of a: "<< a << "\nPinter: " << &a << std::endl;


    
    return 0;
}