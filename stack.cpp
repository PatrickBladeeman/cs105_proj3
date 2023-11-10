#include "Stack.h"
#include <iostream>
using namespace std;

// Constructor
Stack::Stack() {
    top = nullptr;
} 

// Destructor
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

// Check if the stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}

// Push an element onto the stack
void Stack::push(string nameIn, int numIn) {
    Node newNode;
    newNode.name = nameIn;
    newNode.num = numIn;
    top = &newNode;
}

// Pop an element from the stack
void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Peek at the top element of the stack
int Stack::peek() {
    if (!isEmpty()) {
        return top->num;
    } else {
        cerr << "Error: Stack is empty.\n";
        return -1; // You might want to handle this differently based on your application's needs
    }
}

// Display the elements in the stack
void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        cout << current->name << " " << current->num << endl;
        current = current->next;
    }
    cout << "\n";
}