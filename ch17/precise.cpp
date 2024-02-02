#include <iostream>

int main() {
    using std::cout;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    cout.setf(std::ios_base::showpoint);
    cout << "\"Furry Firends\" is  $" << price1 << "!\n";

    cout.precision(2);
    cout << "\"Furry Firends\" is  $" << price1 << "!\n";

    return 0;
}