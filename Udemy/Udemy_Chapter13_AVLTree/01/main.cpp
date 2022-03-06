#include <iostream>

class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
    int height;
};

class AVLtree{
private:
    Node *root;

public:
    AVLtree(){ root = nullptr; }

    int NodeHeight(Node *p){
        int hr, hl;

        hl = p && p->lchild ? p->lchild->height : 0;

        if (p && p->rchild)
            hr = p->rchild->height;
        else
            hr = 0;

        return hl > hr ? hl + 1 : hr + 1;
    }

    int getBalanceFactor(Node *p){
        int hr, hl;
        hl = p && p->lchild ? p->lchild->height : 0;
        hr = p && p->rchild ? p->rchild->height : 0;
        return hl - hr;
    }

    Node *LLRotation(Node *p){
        Node *pl = p->lchild;
        Node *plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;

        p->height = NodeHeight(p);
        pl->height =NodeHeight(pl);

        if (p == root)
            root = pl;
        
        return pl;
    }

    Node *RRRotation(Node *p){
        Node *pr = p->rchild;
        Node *prl = pr->lchild;

        pr->lchild = p;
        p->rchild = prl;

        p->height = NodeHeight(p);
        pr->height =NodeHeight(pr);

        if (p == root)
            root = pr;
        
        return pr;
    }

    Node *LRRotation(Node *p){
        Node *pl = p->lchild;
        Node *plr = pl->rchild;

        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;

        plr->lchild = pl;
        plr->rchild = p;

        p->height = NodeHeight(p);
        pl->height =NodeHeight(pl);
        plr->height =NodeHeight(plr);

        if (p == root)
            root = plr;
        return plr;
    }

    Node *RLRotation(Node *p){
        Node* pr = p->rchild;
        Node* prl = pr->lchild;

        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;
    
        prl->rchild = pr;
        prl->lchild = p;

        pr->height = NodeHeight(pr);
        p->height = NodeHeight(p);
        prl->height = NodeHeight(prl);

        if (p == root)
            root = prl;
        return prl;
    }


    Node *InsertR(Node *p, int key){
        Node *temp = nullptr;
        
        if (p == nullptr){
            temp = new Node;
            temp->data = key;
            temp->height = 1;
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

        p->height = NodeHeight(p);

        if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == 1)
            return LLRotation(p);
        else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == -1)
            return LRRotation(p);
        else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == -1)
            return RRRotation(p);
        else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == 1)
            return RLRotation(p);

        return p;
    }
    
    void Inorder(Node *p) {
        if (p){
            Inorder(p->lchild);
            std::cout << p->data << ", ";
            Inorder(p->rchild);
        }
    }

    Node *getRoot(){
        return root;
    }

};



int main(){
    AVLtree myTree;
    myTree.InsertR(myTree.getRoot(), 50);
    myTree.InsertR(myTree.getRoot(), 10);
    myTree.InsertR(myTree.getRoot(), 20);
    // myTree.InsertR(myTree.getRoot(), 30);
    // myTree.InsertR(myTree.getRoot(), 40);
    // myTree.InsertR(myTree.getRoot(), 60);
    // myTree.InsertR(myTree.getRoot(), 80);

    std::cout << myTree.getBalanceFactor(myTree.getRoot()) << std::endl;
    std::cout << myTree.getRoot()->data << std::endl;
    myTree.Inorder(myTree.getRoot());


    return 0;
}