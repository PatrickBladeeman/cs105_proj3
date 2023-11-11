
#include "Stack.h"
#include "Queue.h"
//#include "Queue.h"
using namespace std;
//#include "Queue.h"

void createQueue(ifstream &inputFile, Queue &queue);
void fillCapsule(int &capNum, string &scheduleName, int &scheduleNum, 
                       int &capLeft, int &totalNum, Queue &queue, Stack &stack);
void printSummary(int numSum, int capNum, int capacity);


int main() {
    Queue queue;
    ifstream inputFile("testcase - 15.txt");
   // create queue
    int capacity;
    inputFile >> capacity;
    // Close the file
    // while (inputFile) {
    //     string name;
    //     int val;
    //     if (inputFile >> name >> val) {
    //         queue.enqueue(name, val);
    //     }
    // }
    createQueue(inputFile, queue);
    // inputFile.close();   

    // 
    int capNum = 0;
    Stack stack;
    int scheduleNum = 0;
    int numSum = 0;
    string scheduleName;

    while(!queue.isEmpty()) {
        capNum++;
        int capLeft = capacity;
        int totalNum = 0;
        fillCapsule(capNum, scheduleName, scheduleNum, capLeft, totalNum, 
                                                                queue, stack);
        // fill in capsule
        // cout << "Capsule #" << capNum << endl;
        
        // queue.peek(&scheduleName, &scheduleNum); // check next group
        
        // while (!queue.isEmpty() && capLeft >= scheduleNum) {
        //     queue.dequeue();
        //     stack.push(scheduleName, scheduleNum);
        //     capLeft -= scheduleNum;
        //     totalNum += scheduleNum;
            
        //     if (!queue.isEmpty()) {
        //         queue.peek(&scheduleName, &scheduleNum);
        //     }
        // }

        // while (!stack.isEmpty()) {
        //     string outName;
        //     int outNum;
        //     stack.pop(&outName, &outNum);
        //     cout << outName << " " << outNum << endl;
        // }
        // cout << "Total guests: " << totalNum << endl; 
        // cout << "Remaining Capacity: " << capLeft << endl;
        // cout << endl;
        numSum += totalNum;
    }
    
    printSummary(numSum, capNum, capacity);
    // print summary
    // cout << "Overall number of guests: " << numSum << endl;
    // cout << "Overall number of capsules: " << capNum << endl;
    // cout << "Capsule Capacity: " << capacity << endl;
    // cout << "Percentage utilization: " << numSum << " / (" << capNum << " * ";
    // cout << capacity << ") = " << setprecision(3) << (double)numSum / (capNum * capacity) *100 << "%" << endl;
    return 0;
}
void createQueue(ifstream &inputFile, Queue &queue){
    while (inputFile) {
        string name;
        int val;
        if (inputFile >> name >> val) {
            queue.enqueue(name, val);
        }
    }
    inputFile.close();   
}

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
        string outName;
        int outNum;
        stack.pop(&outName, &outNum);
        cout << outName << " " << outNum << endl;
    }
    cout << "Total guests: " << totalNum << endl; 
    cout << "Remaining Capacity: " << capLeft << endl;
    cout << endl;
}

void printSummary(int numSum, int capNum, int capacity){
    cout << "Overall number of guests: " << numSum << endl;
    cout << "Overall number of capsules: " << capNum << endl;
    cout << "Capsule Capacity: " << capacity << endl;
    cout << "Percentage utilization: " << numSum << " / (" << capNum << " * ";
    cout << capacity << ") = " << setprecision(3) << (double)numSum / (capNum * capacity) *100 << "%" << endl;
}