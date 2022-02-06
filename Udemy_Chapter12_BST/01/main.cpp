#include <iostream>

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

};




int main(){
    BST mytree;

    std::cout << mytree.getRoot() << std::endl;

    mytree.Insert(10);
    mytree.Insert(5);
    mytree.Insert(20);
    mytree.Insert(8);
    mytree.Insert(30);

    mytree.Inorder(mytree.getRoot());

    std::cout << "\n";

    Node *t = mytree.Search(3);

    if (t)
        std::cout << "found"<< std::endl;
    else
        std::cout << "not found" << std::endl;



    return 0;
}