#include "stack.h"

Stack::Stack() {
    items = new Item[MAX]{0};
    top = 0;
}

Stack::~Stack() {
    delete []items;
}

bool Stack::isempty() const {
    return top == 0;
} 

bool Stack::isfull() const {
    return top == MAX;
}

bool Stack::push(const Item &item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

bool Stack::pop(Item &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return  false;
    }
}

std::ostream& operator<<(std::ostream &os, const Stack &st) {

    for (int i = 0; i < st.top; i++) {
        os << st.items[i];

        if (i != st.top - 1) {
            os << ',';
        }
    }

    return os;
}