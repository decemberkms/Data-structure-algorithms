#include <iostream>


class Node {
public:
    int data;
    Node *next;
}*first, *last = nullptr;

void insert(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    
    if (first == nullptr){
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
}
int count(Node *p);

void Delete(Node *p, int index){
    Node *q;
    int x {-1};

    if (index < 1 || index > count(p)){
        std::cout << "Wrong"<< std::endl;
    }
    if (index == 1){
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        std::cout << "\n" << x << " is deleted\n";
    } else {
        for (int i = 0 ; i < index -1; ++i){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        std::cout << "\n" << x << " is deleted\n";
    }
}

int count(Node *p){
    int c {0};
    while (p != nullptr){
        c++;
        p = p->next;
    }
    return c;
}

void display(Node *p){
    while(p){
        std::cout << p->data << std::endl;
        p = p->next;       
    }
}

void displayRecursion(Node *p){
        if(p != nullptr){
            std::cout << p->data << std::endl;
            displayRecursion(p->next);
        }
}

int main(){
    insert(0);
    insert(1);
    insert(3);
    insert(4);
    insert(6);
    insert(10);
    insert(8);

    Node *p = first;

    display(p);

    p = first;

    Delete(p, 3);
    display(p);


    return 0;
}