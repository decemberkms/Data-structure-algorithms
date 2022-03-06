#include <iostream>

// stack using array

class Stack
{
public:
    int size_s;
    int Top;
    int *s;

    Stack()
        : Stack{0} {};

    Stack(int size_s)
        : size_s{size_s}
    {
        this->s = new int[size_s];
        this->Top = -1;
    }

    ~Stack()
    {
        delete[] this->s;
    }

    void insert_back(const int &x)
    {
        if (this->Top > this->size_s - 2)
        {
            std::cout << "The stack is overflown" << std::endl;
        }
        else
        {
            this->Top++;
            this->s[this->Top] = x;
        }
    }

    int pop_back(){
        int x = -1;

        if (this->Top == -1){
            std::cout << "The stack is underflown" << std::endl;
        } else{
            x = this->s[this->Top];
            this->Top--;
        }
        return x;
    }


    int peek(int index){
        int x = 1;
        
        if (this->Top - index + 1 < 0 || this->Top - index + 1 == this->size_s){
            std::cout << "Invalid position" << std::endl;
        } else{
            x = this->s[this->Top - index + 1];
        }
        return  x;
    }

    int stackTop(){
        if (this->Top == -1){
            return -1;
        } else{
            return this->s[this->Top];
        }
    }

    bool isEmpty(){
        if (this->Top == -1)
            return true;
        else 
            return false;
    }

    bool isFull(){
        if (this->Top == this->size_s -1)
            return true;
        else 
            return false;
    }

    void Display()
    {
        for (int i = this->Top; i >= 0; --i)
        {
            std::cout << this->s[i] << std::endl;
        }
    }
};

int main()
{

    Stack myStack(6);

    myStack.insert_back(1);
    myStack.insert_back(2);
    myStack.insert_back(3);
    myStack.insert_back(4);
    myStack.insert_back(5);
    myStack.insert_back(6);
    myStack.insert_back(7);
    myStack.Display();

    std::cout << "first position" <<": ";
    std::cout << myStack.peek(1) << std::endl;
    myStack.peek(7);
    std::cout << myStack.pop_back() << std::endl;
    std::cout << myStack.pop_back() << std::endl;
    std::cout << myStack.pop_back() << std::endl;
    std::cout << myStack.pop_back() << std::endl;
    std::cout << myStack.pop_back() << std::endl;
    std::cout << myStack.pop_back() << std::endl;
    
    std::cout << myStack.pop_back() << std::endl;



    return 0;
}