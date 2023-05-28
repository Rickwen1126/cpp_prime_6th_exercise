#include "port.h"
#include <iostream>

using namespace std;

int main() {
    Port p("Wen", "gala", 5);
    cout << p << endl;
    p.Show(); 

    VintagePort vp;
    cout << vp << endl;
    vp.Show();

    VintagePort vp2("X", 6, "fuck me", 2000);
    cout << vp2 << endl;
    vp2.Show();
    vp = vp2;

    cout << vp << endl;
    vp.Show();
    

    return 0;
}