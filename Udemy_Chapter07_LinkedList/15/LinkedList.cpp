#include "LinkedList.hpp"

LinkedList::LinkedList(int A[], int n ){
    Node *last , *temp;

    // Create first node       
    first = new Node;
    first->data = A[0];
    first->next = nullptr;

    // point last to the first node as well
    last = first;

    for (int i = 1; i < n; ++i){
        //create temp node
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;

        // point last's next (for the first time, it's the same as first) to temp node
        last->next = temp;

        //point last to temp node
        last = temp;
    }  
}

LinkedList::~LinkedList(){
    Node *p = first;

    while (first){
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display(){
    Node *p = first;

    while (p != nullptr){
        std::cout << p->data << "->";
        p = p->next;
    }
    std::cout << "\\0" << std::endl;
}

int LinkedList::Count(){
    Node *p = first;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool LinkedList::Insert(int index, int x){
    Node *temp, *p = first;

    if (index < 0 || index > Count())
        return false;

    temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    if (index == 0){
        temp->next = first;
        first = temp;
    } else{
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    return true;
}

int LinkedList::Delete(int index){
    index++;
    Node *p, *q = nullptr; //tail pointer

    int x = -1;

    if (index < 1 || index > Count())
        return -1;

    if (index == 1) {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    } else{
        p = first;

        for (int i = 0; i < index - 1; i++){
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}


int LinkedList::Sum(){
    Node *p = first;
    int sum {0};

    while (p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}
