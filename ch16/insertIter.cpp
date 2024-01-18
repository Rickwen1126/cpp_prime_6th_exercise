#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

struct my{
    int a;
    int b;
    ~my() {
        std::cout << "my bye!" << std::endl;
    }
};

int main() {
    using namespace std;
    string s("cobra");
    cout << s.find_first_of("hark");

    return 0;
}