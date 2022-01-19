#include <iostream>
#include <limits>

class Node{
public:
    int data;
    Node *next; // self deferential class
public:

} *first = nullptr;

void create(int A[], int n){
    Node *temp, *last;

    first = new Node;
    
    first->data = A[0];
    first->next = nullptr;
    
    last = first;

    for (int i = 1; i < n; ++i){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;

        last->next = temp;
        last = temp;
    }

}

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

int count(Node *p){
    int c {0};
    while (p != nullptr){
        c++;
        p = p->next;
    }
    return c;
}

int sum(Node *p){
    int sum {0};
    while (p != nullptr){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

auto max_v(Node *p){
    auto max = INT64_MIN;

    while (p){
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

Node* Search(Node *p, int key){
    while(p){
        if (p->data == key){
            return p;
        }
        p = p->next;
    }

    return nullptr;
}


Node* Searchimp(Node *p, int key){
    Node *q = nullptr;
    while(p != nullptr){
        if (p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;

        }
        q = p;
        p = p->next;
    }
    return nullptr;
}



int main(){

    int A[] = {3, 4, 5, 8 , 9, 10, 22, 34, 74};
    int size = sizeof(A) / sizeof(int);

    create(A, size);

    first;

    Node *p = new Node;

    p = first;


    
    return 0;
}