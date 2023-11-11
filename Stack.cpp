// File Name: Stack.cpp
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 11/10/2023
// Assignment Number 3
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// This program schedules groups from waiting queue onto capsules
// Stack.cpp implenments the functions of the Stack class.
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "Stack.h"
using namespace std;


// Stack(): constructor of Stack class; sets top node to NULL
Stack::Stack() {
    top = nullptr;
} 


// ~Stack(): deconstructor of Stack class; deleted allocated data
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

//***********************************************************
// isEmpty(): determines whether a stack is empty
//
// returns: true if stack is empty, false otherwise
//***********************************************************
bool Stack::isEmpty() {
    return top == nullptr;
}

//***********************************************************
// push: push an element to stack
//
// string nameIn: name of group
// int numIn: size of group
//***********************************************************
void Stack::push(string nameIn, int numIn) {
    Node* newNode = new Node; // sets up group info for a stack
    newNode->name = nameIn; 
    newNode->num = numIn; 
    newNode->next = top; 
    top = newNode;
}

//***********************************************************
// pop(): deletes a node from stack while getting its values
//
// string *outName: name of group
// int *numIn: size of group
//***********************************************************
void Stack::pop(string* outName, int* outNum) {
    if (!isEmpty()) {
        Node* temp = top; // accesses the top of stack
        *outName = temp->name;
        *outNum = temp->num;
        top = top->next;
        delete temp;
    } else {
        cerr << "The Stack is Empty" << endl;
    }
}

// pop(): deletes a node from stack 
void Stack::pop() {
     if (!isEmpty()) {
        Node* temp = top; // accesses the top of stack
        top = top->next;
        delete temp;
    } else {
        cerr << "The Stack is Empty" << endl;
    }
}



// peek: checks the group name and size of the element at the top of stack
int Stack::peek() {
    if (!isEmpty()) {
        return top->num;
    } else {
        cerr << "Error: Stack is empty.\n";
        return -1; 
    }
}

