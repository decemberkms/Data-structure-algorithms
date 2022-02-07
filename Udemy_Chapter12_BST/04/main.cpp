#include <iostream>
#include <stack>

class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class BST{
private:
    Node *root;

public:
    BST(){ root = nullptr; }

    int Height(Node *p){
        int x, y;
        
        if (p == nullptr)
            return 0;

        x = Height(p->lchild);
        y = Height(p->rchild);

        return x > y ? x + 1 : y + 1;
    }

    void Insert(int key){
        Node *t = root;
        Node *r, *temp;

        if (root == nullptr){
            temp = new Node;
            temp->data = key;
            temp->lchild = temp->rchild = nullptr;
            root = temp;
            return;
        } 

        while (t != nullptr){
            r = t;

            if (key < t->data)
                t = t->lchild;
            else if (key > t->data)
                t = t->rchild;
            else
                return;
        }

        temp = new Node;
        temp->data = key;
        temp->lchild = temp->rchild = nullptr;

        if (key < r->data) 
            r->lchild = temp;
        else
            r->rchild = temp;
    }

    void Inorder(Node *temp){
        if (temp){
            Inorder(temp->lchild);
            std::cout << temp->data << " ";
            Inorder(temp->rchild);
        }
    }

    Node *InsertR(Node *p, int key){
        Node *temp = nullptr;

        if (p == nullptr){
            temp = new Node;
            temp->data = key;
            temp->rchild = temp->lchild = nullptr;
            if (p == root)
                root = temp;
            else 
                p = temp;
            return temp;
        }


        if (key < p->data)
            p->lchild = InsertR(p->lchild, key);
        else if (key > p->data)
            p->rchild = InsertR(p->rchild, key);
            
        return p;
    }

    Node* getRoot(){
        return root;
    }

    Node* Search(int key){
        Node *temp = root;

        while (temp){
            if (key == temp->data)
                return temp;
            else if (key < temp->data)
                temp = temp->lchild;
            else
                temp = temp->rchild;           
        }
        return nullptr;
    }

    Node *InPre(Node *p){
        while(p && p->rchild != nullptr)
            p = p->rchild;
        return p;
    }


    Node *InSucc(Node *p){
        while(p && p->lchild != nullptr)
            p = p->lchild;
        return p;
    }

    Node* Delete(Node *p, int key){

        Node *q;

        if (p == nullptr)
            return nullptr;
        
        if (p->lchild == nullptr && p->rchild == nullptr){
            if (p == root)
                root =  nullptr;
            delete p;
            return nullptr;
        }

        if (key < p->data)
            p->lchild = Delete(p->lchild, key);
        else if (key > p->data)
            p->rchild = Delete(p->rchild, key);
        else {
            if (Height(p->lchild) > Height(p->rchild)){
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }else{
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }

                
        }
        return p;
    }

    void createFromPreorder(int pre[], int n){
        int i = 0;
        root = new Node;
        root->data = pre[i++];
        root->lchild = root->rchild = nullptr;

        Node *t;
        Node *p = root;
        std::stack<Node*> stk;
        
        while (i < n){
            if (pre[i] < p->data){
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = nullptr;
                p->lchild = t;
                stk.push(p);
                p = t;
            } else{
                if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                    t = new Node;
                    t->data = pre[i++];
                    t->lchild = t->rchild = nullptr;
                    p->rchild = t;
                    p = t;
                } else{
                    p = stk.top();
                    stk.pop();
                }
            }
        }

    }

};




int main(){
    BST mytree;

    std::cout << mytree.getRoot() << std::endl;

    mytree.InsertR(mytree.getRoot(), 10);
    mytree.InsertR(mytree.getRoot(), 5);
    mytree.InsertR(mytree.getRoot(), 1);
    mytree.InsertR(mytree.getRoot(), 11);
    mytree.InsertR(mytree.getRoot(), 12);
    mytree.InsertR(mytree.getRoot(), 3);
    mytree.InsertR(mytree.getRoot(), 30);

    mytree.Inorder(mytree.getRoot());
    mytree.Delete(mytree.getRoot(), 10);
    mytree.Delete(mytree.getRoot(), 11);
    mytree.Delete(mytree.getRoot(), 1);
    std::cout << "\n";
    mytree.Inorder(mytree.getRoot());


    std::cout << "\n";
    std::cout << mytree.Height(mytree.getRoot()) << std::endl;
    std::cout << "\n";

    Node *t = mytree.Search(1);

    if (t)
        std::cout << "found"<< std::endl;
    else
        std::cout << "not found" << std::endl;

    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    BST b;
    b.createFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    std::cout << "\n";

    return 0;
}