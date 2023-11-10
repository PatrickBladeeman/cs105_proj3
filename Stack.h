#ifndef Stack_h
#define Stack_h
#include "Queue.h"



class Stack {
private:
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