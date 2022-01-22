#include <iostream>
#include <limits>
#include <iomanip>

class Node {
public:
    int data;
    Node *next;
}*first = nullptr, *second = nullptr, *third = nullptr, *last1= nullptr, *last2 = nullptr;

int count(Node *p);

void createFirst(int A[], int n){
    Node *temp;

    first = new Node;
    
    first->data = A[0];
    first->next = nullptr;
    
    last1 = first;

    for (int i = 1; i < n; ++i){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;

        last1->next = temp;
        last1 = temp;
    }

}

void createSecond(int A[], int n){
    Node *temp;

    second = new Node;
    
    second->data = A[0];
    second->next = nullptr;
    
    last2 = second;

    for (int i = 1; i < n; ++i){
        temp = new Node;
        temp->data = A[i];
        temp->next = nullptr;

        last2->next = temp;
        last2 = temp;
    }

}

// void insert(Node*p, int x){
//     Node *temp = new Node;
//     temp->data = x;
//     temp->next = nullptr;
    
//     if (first == nullptr){
//         first = last = temp;
//     } else {
//         last->next = temp;
//         last = temp;
//     }
// }

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
    std::cout << "\\0" << std::endl;
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

void rmDuplicate(Node *p){

    Node * q = p->next;

    while(q){
        if (p->data != q->data){
            p = q;
            q = q->next;
        } else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverseElement(Node *p, int size_Array){
    int Array[size_Array] {0};
    int i = 0;

    while(p){
        Array[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while(p){
        p->data= Array[i--];
        p = p->next;
    }
}

void reversePointers(Node *p){
    Node* q = nullptr;
    Node* r = nullptr;
    
    while (p != nullptr){
        r = q;
        q = p;
        p = p->next;
        q->next = r;        
    }
}

void mergerTwo(Node* p, Node* q){
    Node* last;
    if (p->data < q->data){
        third = last = p;
        p = p->next;
        third->next = nullptr;

    } else{
        third = last = q;
        q = q->next;
        third->next = nullptr;
    }

    while (p && q){
        if (p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        } else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }        
    }

    if (p != nullptr) last->next = p;
    if (q != nullptr) last->next = q;
}

int main(){
    int A[] = {2,4,6,8,10};
    int B[] = {1,3,5,7,9};

    int sizeN = sizeof(A) / sizeof(int);
    createFirst(A, sizeN);
    createSecond(B, sizeN);

    
    mergerTwo(first, second);

    display(third);

    


    return 0;
}