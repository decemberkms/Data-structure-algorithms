#include <iostream>
#include <limits>

class Node{
public:
    int data;
    Node *next; // self referential class
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



void Insertion(Node*p, int pos, int x){
    Node *temp;

    if (pos == 0){
        
        temp = new Node;
        
        temp->data = x;
        temp->next = first;
        
        first = temp;

    } else if (pos > 0){
        p = first;
        for (int i = 0; i < pos -1 && p; ++i)
            p = p->next;
        if (p){
            temp = new Node;
            
            temp->data = x;
            temp->next = p->next;

            p->next = temp;
        }

    }

}

int main(){

    int A[] = {3, 4, 5, 8 };
    int size = sizeof(A) / sizeof(int);

    create(A, size);

    Node *p = new Node;

    p = first;




    Insertion(first, 0, 99);
    // Insertion(first, 1, 2);
    displayRe1(first);

    
    return 0;
}