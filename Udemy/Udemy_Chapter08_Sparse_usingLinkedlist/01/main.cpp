#include <iostream>

class Node{
public:
    int col;
    int data;
    Node *next;
};


// class SparseMaxtrix{
// private:
//     Node *first;
// public:
//     SparseMaxtrix(){

//     }

// };


int main() {

    Node *Array[5];

    Array[0] = new Node;
    Array[0]->col = 1;
    Array[0]->data = 3;
    Array[0]->next = nullptr;

    Array[1] = new Node;
    Array[1]->col = 0;
    Array[1]->data = 5;
    Array[1]->next = nullptr;

    Array[2] = new Node;
    Array[2]->col = 2;
    Array[2]->data = 7;
    Array[2]->next = nullptr;

    

    Node *temp = new Node;
    
    // temp = new Node;
    temp->col = 4;
    temp->data = 2;
    temp->next = nullptr;
    
    Array[2]->next = temp;

    Array[3] = new Node;
    Array[3]->col = 3;
    Array[3]->data = 1;
    Array[3]->next = nullptr;


    for (int i = 0; i < 5; ++i){
        Node *p = Array[i];

        for (int j = 0; j < 5; ++j){
            if (j == p->col){
                std::cout << p->data << " ";
                if (p->next)
                    p = p->next;
            } else {
                std::cout << "0 ";
            }
        
        }
        std::cout << std::endl;

    }

    return 0;
}