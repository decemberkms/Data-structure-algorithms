#include <iostream>

class Node {
public:
    Node *prev;
    int data;
    Node *next;    
};

class DoublyLL {
private:
    Node *first;
public:
    DoublyLL() {first = nullptr;}

    DoublyLL(int A[], int n){
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

    void Display(){
        Node *p = first;

        while (p != nullptr){
            std::cout << p->data << "->";
            p = p->next;
        }
        std::cout << "\\0" << std::endl;
    }

};

int main(){
    int A[] = {9,2,3,4,5,6,7,8};

    DoublyLL Darray(A, sizeof(A) / sizeof(int));
    Darray.Display();



    return 0;
}