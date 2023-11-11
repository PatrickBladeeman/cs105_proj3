
// File Name: DarkZone.cpp
//
// Authors: Bryan Zhao, Regina Zhou
// Date: 11/10/2023
// Assignment Number 3
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// This program schedules groups from waiting queue onto capsules
// DarkZone.cpp is the main execution program.
#include "Stack.h"
#include "Queue.h"
using namespace std;

void createQueue(ifstream &inputFile, Queue &queue);
void fillCapsule(int &capNum, string &scheduleName, int &scheduleNum, 
                       int &capLeft, int &totalNum, Queue &queue, Stack &stack);
void printSummary(int numSum, int capNum, int capacity);

//***********************************************************
// main: manages entire execution of program
// returns: 0
//***********************************************************
int main() {
    Queue queue;
    ifstream inputFile("testcase15.txt");

    int capacity; // numeric value for capacity of each capsule
    inputFile >> capacity;
    createQueue(inputFile, queue);
    
    int capNum = 0; // numeric value for number fo capsules used
    Stack stack; // stack representing each capsule's seats
    int scheduleNum = 0; // numeric value of group size 
    int numSum = 0; // numeric bale of total people in the queue
    string scheduleName;

    while(!queue.isEmpty()) {
        capNum++;
        int capLeft = capacity; // numeric value of empty spots in capsule
        int totalNum = 0; // total number of people in each capsule
        fillCapsule(capNum, scheduleName, scheduleNum, capLeft, totalNum, 
                                                                queue, stack);
        numSum += totalNum;
    }
    
    printSummary(numSum, capNum, capacity);
    return 0;
}

//***********************************************************
// createQueue: creates a queue from the input file
//
// ifstream &inputFile: input file passed in
// Queue &queue: queue that stores the values from input file
//***********************************************************
void createQueue(ifstream &inputFile, Queue &queue){
    while (inputFile) {
        string name; // string storing group name 
        int val; // numeric value of group size
        if (inputFile >> name >> val) {
            queue.enqueue(name, val);
        }
    }
    inputFile.close();   
}

//***********************************************************
// fillCapsule: Fills each capsule with group members
//
// int &capNum: reference to integer that stores number of capsules used
// string &scheduleName: reference to string that stores the group name
// int &scheduleNum: reference to integer that stores the group size
// int &capLeft: reference to integer that stores empty spaces in capsule
// int &totalNum: reference to total guests in one capsule
// Queue &queue: reference to the current queue
// Stack &stack: reference to the stack of groups
//***********************************************************
void fillCapsule(int &capNum, string &scheduleName, int &scheduleNum, 
                       int &capLeft, int &totalNum, Queue &queue, Stack &stack){
    
    cout << "Capsule #" << capNum << endl;
    queue.peek(&scheduleName, &scheduleNum); // check next group
        
    while (!queue.isEmpty() && capLeft >= scheduleNum) {
        queue.dequeue();
        stack.push(scheduleName, scheduleNum);
        capLeft -= scheduleNum;
        totalNum += scheduleNum;
            
        if (!queue.isEmpty()) {
            queue.peek(&scheduleName, &scheduleNum);
        }
    }

    while (!stack.isEmpty()) {
        string outName; // string storing group name
        int outNum; // numeric value of group size
        stack.pop(&outName, &outNum);
        cout << outName << " " << outNum << endl;
    }
    cout << "Total guests: " << totalNum << endl; 
    cout << "Remaining Capacity: " << capLeft << endl;
    cout << endl;
}

//***********************************************************
// printSummary: prints tha summary data
//
// int numSum: integer storing total number of guests in queue
// int capNum: integer storing total number of capsules used
// int capacity: integer storing the number of spots in each capsule
//***********************************************************
void printSummary(int numSum, int capNum, int capacity){
    cout << "Overall number of guests: " << numSum << endl;
    cout << "Overall number of capsules: " << capNum << endl;
    cout << "Capsule Capacity: " << capacity << endl;
    cout << "Percentage utilization: " << numSum << " / (" << capNum << " * ";
    cout << capacity << ") = " << setprecision(3) << (double)numSum / 
                                        (capNum * capacity) *100 << "%" << endl;
}