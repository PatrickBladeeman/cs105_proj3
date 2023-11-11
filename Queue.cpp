// File Name: Queue.cpp
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 11/10/2023
// Assignment Number 3
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// This program schedules groups from waiting queue onto capsules
// Queue.cpp implements the specific functions of the Queue class.
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;

// Queue(): constructor of Queue class; sets first and last node to NULL
Queue::Queue() {
    first = nullptr;
    last = nullptr;
}

// ~Queue(): deconstructor of Queue class; deleted allocated data
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

//***********************************************************
// isEmpty(): determines whether a queue is empty
//
// returns: true if queue is empty, false otherwise
//***********************************************************
bool Queue::isEmpty() {
    return first == nullptr;
}

//***********************************************************
// enqueue: addes an element to queue
//
// string nameIn: name of group
// int numIn: size of group
//***********************************************************
void Queue::enqueue(string nameIn, int numIn) {
    Node* newNode = new Node; // sets up new node for a group
    newNode->name = nameIn; // sets up group name of the node
    newNode->num = numIn; // sets up group size of the node 
    newNode->next = nullptr;
    if (isEmpty()) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

//***********************************************************
// dequeue(): deletes the front node from queue
//***********************************************************
void Queue::dequeue() {
    Node* frontAddr = first; // accesses the first element of the queue
    first = first->next;
    if(first == nullptr) {
        last = nullptr;
    }
    delete frontAddr;
}

//***********************************************************
// peek: checks the group name and size of the element at the front of queue
//
// string* scheduledName: string that should get the group name
// int* scheduledNum: integer that should get the group sizes
//***********************************************************
void Queue::peek(string* scheduledName, int* scheduledNum) {
    if (!isEmpty()) {
        *scheduledName = first->name;
        *scheduledNum = first->num;
    } else {
        cerr << "Error: Stack is empty.\n";
    }
  
    
}