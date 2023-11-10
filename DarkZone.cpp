
#include "Stack.h"
#include "Queue.h"
//#include "Queue.h"
using namespace std;
//#include "Queue.h"



int main() {
    Queue q;
    ifstream inputFile("DarkZone.txt");
    int capacity;
    inputFile >> capacity;
    // cout << "cap: " << capacity << endl;
    // Close the file
    while (inputFile) {
        string name;
        int val;
        if (inputFile >> name >> val) {
            q.enqueue(name, val);
        }
    }
    inputFile.close();   

    int capNum = 0;
    Stack s;
    int scheduleNum = 0;
    int numSum = 0;
    string scheduleName;

    while(!q.isEmpty()) {
        capNum++;
        int capLeft = capacity;
        int totalNum = 0;
        
        cout << "Capsule #" << capNum << endl;
        
        q.peek(&scheduleName, &scheduleNum); // check next group
        
        while (!q.isEmpty() && capLeft >= scheduleNum) {
            q.dequeue();
            s.push(scheduleName, scheduleNum);
            capLeft -= scheduleNum;
            totalNum += scheduleNum;
            
            //cout << "currently checking name: " << scheduleName << " and num: " << scheduleNum << endl;
            if (!q.isEmpty()) {
                q.peek(&scheduleName, &scheduleNum);
                //cout << "currently checking name: " << scheduleName << " and num: " << scheduleNum << endl;
            }
        }

        while (!s.isEmpty()) {
            string outName;
            int outNum;
            s.pop(&outName, &outNum);
            cout << outName << " " << outNum << endl;
        }
        cout << "Total guests: " << totalNum << endl; 
        cout << "Remaining Capacity: " << capLeft << endl;
        cout << endl;
        //cout << "util percentage: " << (totalNum / capacity) << endl;
        numSum += totalNum;
    }
    cout << "Overall number of guests: " << numSum << endl;
    cout << "Overall number of capsules: " << capNum << endl;
    cout << "Capsule Capacity: " << capacity << endl;
    cout << "Percentage utilization: " << numSum << " / (" << capNum << " * ";
    cout << capacity << ") = " << setprecision(3) << (double)numSum / (capNum * capacity) *100 << "%" << endl;
    return 0;
}