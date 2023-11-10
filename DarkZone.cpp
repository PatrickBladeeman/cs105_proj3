
#include "Stack.h"
//#include "Queue.h"
using namespace std;
//#include "Queue.h"



int main() {
    // Queue* qptr = new Queue();
    // string str = "damn ok";
    // qptr->enqueue(str, 45);
    // qptr->display();
    Queue q;
    string str = "damn ok";
    q.enqueue(str, 45);
    q.display();
    return 0;
}