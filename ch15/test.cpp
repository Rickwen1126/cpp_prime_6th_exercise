#include <iostream>

int main() {
    struct dat {short a; short b;};
    long value = 0xA224B118;
    dat *pd = reinterpret_cast<dat*>(&value);
    std::cout << std::hex << pd->b;

    return 0;
}