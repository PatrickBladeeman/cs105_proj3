
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

// Node structure for the linked list



// Dynamic Queue class

#ifndef Queue_h
#define Queue_h
class Queue {

    private:
        struct Node {
            string name;
            int num;
            Node* next;
        // Node(const T& val) : data(val), next(nullptr) {}
        }; 
        Node* first; // Front of the queue
        Node* last;  // Rear of the queue

    public:
        // Constructor
        
        Queue();

        // Destructor
        ~Queue();
        // Check if the queue is empty
        bool isEmpty();

        // Enqueue a new element
        void enqueue(string, int);

        // Dequeue an element
        void dequeue();

        // Display the elements in the queue
        void display();

        int peek();

};

#endif