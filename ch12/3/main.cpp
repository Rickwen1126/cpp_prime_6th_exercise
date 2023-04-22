#include "stock.h"
#include <iostream>

int main(int argc, char *argv[]) {

    Stock s1;
    Stock s2("123", 10, 100);

    // s1.show();
    // s2.show();
    std::cout << s1 << s2;

    return 0;
}