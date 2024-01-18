#include <iostream>
#include <memory>
#include <string>

struct test{
    std::string str;
    test(const std::string &str) : str(str) {
    }

    ~test() {
        std::cout << "test is be destrcut now" << std::endl;
    }

    friend std::ostream & operator<<(std::ostream &os, const test &t);
};

std::ostream &operator<<(std::ostream &os, const test &t) {
    os << t.str;
    return os;    
}

int main() {

    
    std::cout << "done";

    return 0;
}