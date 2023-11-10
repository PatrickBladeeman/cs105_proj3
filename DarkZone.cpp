
#include "Stack.h"
#include "Queue.h"
//#include "Queue.h"
using namespace std;
//#include "Queue.h"



int main() {
    // Queue* qptr = new Queue();
    // string str = "damn ok";
    // qptr->enqueue(str, 45);
    // qptr->display();
    Queue q;
    // string str = "damn ok";
    // q.enqueue(str, 45);
    // q.enqueue("wtf bro", 74);
    // q.display();

    
    ifstream inputFile("DarkZone.txt");
    int capacity;
    inputFile >> capacity;

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Loop as long as there's more input
    while (inputFile) {
        // Read the name and value from each line
        string name;
        int value;
        // getline(inputFile, line);
        // line
        inputFile >> name;
        inputFile >> value;

      
        
        q.enqueue(name, value);
    }

    // Close the file
    inputFile.close();   
    q.display();

    return 0;
}