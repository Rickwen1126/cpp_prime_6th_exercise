#include <iostream>
#include <cstring>
#include "Person.h"
#include "../ex3/QueueTp.h"

const int SIZE = 5;

std::pair<std::string, std::string> GetPersonName() {
    using std::cin;
    using std::cout;
    using std::endl;
    std::string first;
    std::string last;
    cout << "Please enter first name & last name: ";
    cin >> first;
    cin >> last;
    return {first, last};
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Queue<Person *> personQue(SIZE);

    int ct;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "Enter the Person category:\n"
            << "p: Person  g:Gunslinger  "
            << "c: PokerPlayer  b: BadDude "
            << "q: quit\n";
        cin >> choice;
        while(strchr("pgcbq", choice) == nullptr) {
            cout << "Please enter a p, g ,c, b or q: ";
            cin >> choice;
        }

        if (choice == 'q') {
            break;
        }

        switch (choice)
        {
        case 'p': {
            personQue.enqueue(new Person);
            break;
        } 
        case 'g': {
           personQue.enqueue(new Gunslinger);
           break;
        } 
        case 'c': {
            personQue.enqueue(new PokerPlayer);
            break;
        }
        case 'b': {
            personQue.enqueue(new BadDude); 
            break;
        }
        default:
            break;
        }
        cin.get();
        personQue[ct]->Set();
        personQue[ct]->Show();
    }

    cout << "\nHere is your staff:\n";

    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        personQue[i]->Show();
    }

    for (i = 0; i < ct; i++) {
        delete personQue[i];
    }
    cout << "Bye.\n";
    return 0;
}