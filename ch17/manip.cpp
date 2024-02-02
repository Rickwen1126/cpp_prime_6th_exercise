#include <iostream>

int main() {
    using namespace std;
    cout << "Enter an integer: ";
    int n;
    cin >> n;


    cout.width(12);
    cout << "n    n*n\n";
    cout << n << "    " << n*n << "  (decimal)\n";

    cout << hex;
    cout << n << "    " << n*n << "  (hexadecimal)\n";

    cout << oct;
    cout << n << "    " << n*n << "  (octal)\n";

    dec(cout);
    cout << n << "    " << n*n << "  (decimal)\n";


    return 0;
}