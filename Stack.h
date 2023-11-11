// File Name: Stack.h
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 11/10/2023
// Assignment Number 3
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// This program schedules groups from waiting queue onto capsules
// Stack.h initializes the Stack class needed by the program.
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
        string name; // string storing group name
        int num; // numeric value storing group size
        Node* next; // pointer to next node in list
    }; 
    Node* top; // last element in the stack

public:
    // Constructor
    Stack();

    // Deconstructor
    ~Stack();

    // Stack operations
    bool isEmpty();

    // Pushe an element in to stack
    void push(string, int);

    // Pop an element from stack while getting its string and int values
    void pop(string*, int*);

    // Pop the top of stack
    void pop();

    // Check value on top of stack
    int peek();
};

#endif