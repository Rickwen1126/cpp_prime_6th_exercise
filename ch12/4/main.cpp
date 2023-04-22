#include "stack.h"
#include <iostream>

int main(){

    Stack st;

    st.push(123);
    st.push(223);
    st.push(555);

    std::cout << st;

    return 0;
}