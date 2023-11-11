#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "Queue.h"

using namespace std;

// Node structure for the linked list

// Dynamic Queue class
    // Constructor

Queue::Queue() {
    first = nullptr;
    last = nullptr;
}
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}
bool Queue::isEmpty() {
    return first == nullptr;
}

void Queue::enqueue(string nameIn, int numIn) {
    Node* newNode = new Node;
    newNode->name = nameIn;
    newNode->num = numIn;
    newNode->next = nullptr;
    if (isEmpty()) {
        first = last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

void Queue::dequeue() {
    Node* frontAddr = first;
    first = first->next;
    if(first == nullptr) {
        last = nullptr;
    }
    delete frontAddr;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* current = first;
    while (current != nullptr) {
        cout << current->name << " | " << current->num << endl;
        current = current->next;
    }
    cout << "\n";
}

void Queue::peek(string* scheduledName, int* scheduledNum) {
    if (!isEmpty()) {
        *scheduledName = first->name;
        *scheduledNum = first->num;
    } else {
        cerr << "Error: Stack is empty.\n";
        //stack empty
    }
  
    
}