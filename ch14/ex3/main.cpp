#include <iostream>
#include <cstring>
#include "workmi.h"
#include "QueueTp.h"

const int SIZE = 5;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Queue<Worker *> lolas(SIZE);

    int ct;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s:singer  "
            << "t: singing waiter q: quit\n";
        cin >> choice;
        while(strchr("wstq", choice) == nullptr) {
            cout << "Please enter a w, s ,t or q: ";
            cin >> choice;
        }

        if (choice == 'q') {
            break;
        }

        switch (choice)
        {
        case 'w': lolas.enqueue(new Waiter);
            break;
        case 's': lolas.enqueue(new Singer);
            break;
        case 't': lolas.enqueue(new SingingWaiter);
            break;
        default:
            break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";

    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        lolas[i]->Show();
    }

    for (i = 0; i < ct; i++) {
        delete lolas[i];
    }
    cout << "Bye.\n";
    return 0;
}