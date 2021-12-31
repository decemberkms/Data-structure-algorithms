#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

class Array {
private:
    int* A;
    int size;
    int length;

public:
    Array(int size);
    ~Array();

    void create();
    void display();
    void append(int x);
    void insert(int index, int x);
    int e_delete(int index);


};




#endif