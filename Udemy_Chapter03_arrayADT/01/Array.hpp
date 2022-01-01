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
    int Delete(int index);
    int linearSearch(int key);
    void swap(int &x, int &y);
    int binarySearch_loop(int low, int high, int key);
    int binarySearch_recursive(int low, int high, int key);
};

#endif