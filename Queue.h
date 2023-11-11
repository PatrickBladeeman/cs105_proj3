// File Name: Queue.h
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 11/10/2023
// Assignment Number 3
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// This program schedules groups from waiting queue onto capsules
// Queue.h initializes the Queue class needed by the program.
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;
// Dynamic Queue class

#ifndef Queue_h
#define Queue_h
class Queue {

    struct Node {
            string name; // string storing group name
            int num; // numeric value storing group size
            Node* next; // pointer to next node in list
    }; 
    private:
        Node* first; // pointer to front of the queue
        Node* last;  // pointer to end of the queue

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

        // Check the front element
        void peek(string*, int*);

};

#endif