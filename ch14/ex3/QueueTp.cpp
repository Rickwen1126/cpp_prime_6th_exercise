#include "QueueTp.h"
#include <cstdlib>

template <typename T>
Queue<T>::Queue(int qs) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
}

template <typename T>
Queue<T>::~Queue() {
    Node* temp;
    while(front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
bool Queue<T>::isempty() const {
    return items == 0;
}

template <typename T>
bool Queue<T>::isfull() const {
    return items == qsize;
}

template <typename T>
int Queue<T>::queuecount() const {
    return items;
}

template <typename T>
bool Queue<T>::enqueue(const T &item) {
    if (isfull()) 
        return false;
    Node *add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr){
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;

    return true;
}

template <typename T>
bool Queue<T>::dequeue(T &item) {
    if (front == nullptr) {
        return false;
    }

    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;

    return true;
}

template <typename T>
T& Queue<T>::operator[](int i) const{
    T temp; 
    if (i >= items) {
        return temp; // not allowed, should throw exception
    }

    Node *cur = front;
    while(i--) {
        cur = cur->next;
    }

    if (cur != nullptr){
        return cur->item;
    }

    return temp;
}

template <typename T>
bool Queue<T>::deleteNodeByIdx(int i) {
    if (i >= items) return false;

    Node *pre = nullptr;
    Node *cur = front;
    while(i--) {
        pre = cur;
        cur = cur->next;
    }

    if (cur == nullptr) {
        return false;
    }

    if (pre != nullptr){
        pre->next = cur->next;
    } else {
        front = cur->next;
    }

    items--;
    delete cur;

    if (items == 0) {
        rear = nullptr;
    }

    return true;
}
