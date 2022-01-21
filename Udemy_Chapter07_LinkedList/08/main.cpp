#include <iostream>
#include <limits>
#include <iomanip>

class Node {
public:
    int data;
    Node *next;
}*first, *last = nullptr;

int count(Node *p);

void create(int A[], int n){
    Node *temp;

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

int sum(Node *p){
    int sum {0};
    while (p != nullptr){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

void display(Node *p){
    while(p){
        std::cout << p->data << "->";
        p = p->next;       
    }
    std::cout << 0 << std::endl;
}

void displayRecursion(Node *p){
        if(p != nullptr){
            std::cout << p->data << std::endl;
            displayRecursion(p->next);
        }
}

bool sorted(Node *p){
    int x = INT16_MIN;
    while(p){
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;        
    }
    return true;
}

int main(){
    int A[] = {0,1,2,3,4,5,6,7,8,9};
    create(A, 10);
    

    Node *p = first;
    
    display(p);
    
    std::cout << std::boolalpha << sorted(p) << std::endl;

    return 0;
}