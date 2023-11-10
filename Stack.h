#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

#ifndef Stack_h
#define Stack_h




class Stack {

private:
    struct Node {
        string name;
        int num;
        Node* next;
    // Node(const T& val) : data(val), next(nullptr) {}
    }; 
    Node* top;

public:
    // Constructor and Destructor
    Stack();
    ~Stack();

    // Stack operations
    bool isEmpty();
    void push(string, int);
    void pop();
    int peek();
    void display();
};

#endif