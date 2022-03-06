#include <iostream>
#include <limits>

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


Node* Searchimp(Node *p, int key,Node* head){
    Node *q = nullptr;
    while(p != nullptr){
        if (p->data == key){
            q->next = p->next;
            p->next = head;
            head = p;

        }
        q = p;
        p = p->next;
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
    

    std::cout << Search(p,10)->data << std::endl;

    
    return 0;
}