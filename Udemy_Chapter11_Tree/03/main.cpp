#include "QueueCpp.hpp"

using namespace std;

class Tree{
private:
    Node *root;
public:
    Tree() {root = nullptr;}
    // ~Tree(){};

    Node * getRoot(){ return root;}

    void CreateTree(){
        Node *p, *t;
        int x;
        Queue q(25);

        root = new Node;
        cout << "Enter root value: " << flush;   
        cin >> x;

        root->data = x;
        root->lchild = root->lchild = nullptr;
        q.Enqueue(root);

        while(!q.isEmpty()){
            p = q.Dequeue();

            cout << "Enter left child value of " << p->data << ": " << flush;
            cin >> x;

            if (x != -1){
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = nullptr;
                p->lchild = t;
                q.Enqueue(t);
            }    

            cout << "Enter right child value of " << p->data << ": " << flush;
            cin >> x;
            if (x != -1){
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = nullptr;
                p->rchild = t;
                q.Enqueue(t);
            } 
        }
    }

    void Preorder(Node *p){
        if (p){
            cout << p->data << ", " << flush;
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Inorder(Node *p){
        if (p){
            Inorder(p->lchild);
            cout << p->data << ", " << flush;
            Inorder(p->rchild);
        }
    }

    void Postorder(Node *p){
        if (p){
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout << p->data << ", " << flush;           
        }
    }

   

};



int main(){

    Tree t;
 
    t.CreateTree();
    t.Preorder(t.getRoot());

    return 0;
} 