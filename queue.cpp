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
    Node* newNode;
    newNode->name = nameIn;
    newNode->num = numIn;
    if (isEmpty()) {
        first = last = newNode;
    } else {
        last->next = newNode;
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

int Queue::peekNum() {
    return last->num;
}
