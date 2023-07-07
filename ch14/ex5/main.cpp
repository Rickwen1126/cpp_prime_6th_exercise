#include "emp.h"
#include <iostream>

using namespace std;

int main(void) {
    // employee em("Trip", "Harris", "Thumper");
    // cout << em << endl;
    // em.ShowAll();
    // manager ma("Amorphia", "Spindragon", "Nuancer");
    // cout << ma << endl;
    // ma.ShowAll();

    // fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    // cout << fi << endl;
    // fi.ShowAll();

    // highfink hf(ma, "Curly Kew");
    // cout << hf << endl;
    // hf.ShowAll();

    // cout << "Press a key for next phase:\n";
    // cin.get();
    // highfink hf2;
    // hf2.SetAll();

    // cout << "Using an abstr_emp *pointer:\n";
    // abstr_emp tri[4] =  {em, fi, hf, hf2};
    // for (int i = 0; i < 4; i++) {
    //     tri[i].ShowAll();
    // }
    int choice;
    cin >> choice;
    while(choice != 5) {
        cout << choice;
        cin >> choice;
    }
    return 0;
}