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
            auto namePair = GetPersonName();
            personQue.enqueue(new Person(namePair.first, namePair.second));
            break;
        } 
        case 'g': {
            auto namePair = GetPersonName();
            double t = 0;
            int n = 0;
            cout << "Please enter Gunslinger draw time:";
            cin >> t;
            cout << "Please enter Gunslinger notches:";
            cin >> n;
            auto gunslinger = new Gunslinger(Person(namePair.first, namePair.second), t, n);
            personQue.enqueue(gunslinger);
            cout << "Gunslinger do draw with time:" << gunslinger->Draw() << endl;
            break;
        } 
        case 'c': {
            auto namePair = GetPersonName();
            auto pokerPlayer = new PokerPlayer(Person(namePair.first, namePair.second));
            personQue.enqueue(pokerPlayer);
            cout << "PokerPlayer do draw with card:" << pokerPlayer->Draw() << endl;
            break;
        }
        case 'b': {
            auto namePair = GetPersonName();
            double t = 0;
            int n = 0;
            cout << "Please enter BadDude draw time:";
            cin >> t;
            cout << "Please enter BadDude notches:";
            cin >> n;
            auto badDude = new BadDude(Person(namePair.first, namePair.second), t, n);
            personQue.enqueue(badDude);
            cout << "BadDude do draw gun with time:" << badDude->Gdraw() << endl;
            cout << "BadDude do draw card:" << badDude->Cdraw() << endl;
            break;
        }
        default:
            break;
        }
        cin.get();
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