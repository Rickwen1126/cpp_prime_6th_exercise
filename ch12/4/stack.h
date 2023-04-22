#ifndef STACK_H_
#define STACK_H_
#include <iostream>

typedef unsigned long Item;

class Stack {
    private: 
        enum {MAX = 10};
        Item *items;
        int top;
    public:
        Stack();
        ~Stack();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item &item);
        bool pop(Item &item);
        friend std::ostream& operator<<(std::ostream &os, const Stack &st);
};

#endif