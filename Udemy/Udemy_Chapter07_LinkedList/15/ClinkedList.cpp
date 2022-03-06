#include "ClinkedList.hpp"

ClinkList::ClinkList(int A[], int n){
    Node* temp;
    Node* tail;

    head =  new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; ++i){
        temp = new Node;

        temp->data = A[i];
        temp->next = tail->next;
        
        tail->next = temp;
        tail = temp;

    }

}

ClinkList::~ClinkList(){
    Node* p = head;

    while (p->next != head){
        p = p->next;
    }

    while(p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head){
        delete head;
        head = nullptr;
    }
}

int ClinkList::Count(){
    Node *p = head;
    int count {0};
    do {
        p = p->next;
        count++;
    }while((p != head));
    return count;
}

void ClinkList::Display(){
    Node* p = head;
    do {
        std::cout << p->data << "->" << std::flush;
        p = p->next;
    } while(p != head);
    std::cout << "\\0" << std::endl;
}

void ClinkList::recursiveDisplay(Node *p){
    static int flag = 0;
    
    if (p != head || flag == 0){
        flag = 1;
        std::cout << p->data << "->" << std::flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}

void ClinkList::Insert(int index, int x){
    Node *temp, *p;
    if (index == 0){
        temp = new Node;
        temp->data = x;
        if (head == NULL){
            head = temp;
            head->next = head;
        } else{
            p = head;
            while (p->next != head)
                p = p->next;
            p->next = temp;
            temp->next = head;
            head = temp;
        }
    } else {
        p = head;
        for (int i = 0; i < index - 1; ++i)
            p = p->next;
        temp = new Node;
        temp->data = x;
        temp->next = p->next;
        p->next = temp;
    
    }
}

int ClinkList::Delete(int index){
    Node *p;
    int x;

    if (index < 0 || index > Count())
        return -1;

    if (index == 0){
        p = head;
        while (p->next != head)
            p = p->next;
        p->next = head->next;
        x = head->data;
        if (p == head){
            delete head;
            head = nullptr;
        } else {
            delete head;
            head = p->next;
        }
        return x;
    } else{
        p = head;
        for (int i = 0; i < index -2; ++i)
            p = p->next;
        Node *q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
        return x;
    }

}