#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue() {
    Node * temp;
    while(front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}
