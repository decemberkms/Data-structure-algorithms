#include "QueueCpp.cpp"

using namespace std;

class Tree{
private:
    Node *root;
public:
    Tree() {root = nullptr;}
    ~Tree();
    void CreateTree(){
        Node *p, *t;
        int x;
        Queue q(25);

        root = new Node;
        cout << "Enter root value: " << flush;   
        cin >> x;

        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.Enqueue(t);
        }    
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.Enqueue(t);
        } 

    }

};



int main(){

    Tree t;
 
    t.CreateTree();

    return 0;
} 