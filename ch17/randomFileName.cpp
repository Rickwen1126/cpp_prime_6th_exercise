#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    using namespace std;
    ostringstream sout;

    sout << "fuck me\n";
    sout << 1.345 << endl;
    sout << "you are like shit\n";

    string s = sout.str();

    sout << "fuck again\n";

    s = sout.str();

    cout << s << endl;

    istringstream sin(s);

    char c;
    while ((c = sin.get()) != EOF) {
        cout << c;
    }

    return 0;
}