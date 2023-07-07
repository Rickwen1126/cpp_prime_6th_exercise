#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>
#include <random>

class Person {
    private:
        std::string firstName;
        std::string lastName;
    protected:
        void input() {
            std::cout << "Please enter first name:";
            std::cin >> firstName;
            std::cout << "Please enter last name:";
            std::cin >> lastName;
        }

        void data() const{
            std::cout << "First Name: " << firstName << std::endl;
            std::cout << "Last Name: " << lastName << std::endl;
        }
    public:
        Person(const std::string &first = "noname", const std::string &last = "nolastname") : firstName(first), lastName(last) {}

        Person(const Person& p) : firstName(p.firstName), lastName(p.lastName) {}
        
        virtual void Show() const {
            std::cout << "Person" << std::endl;
            data();
        };

        virtual void Set() {
            input();
        }

};


class Gunslinger : virtual public Person {
    private:
        double time;
        int notches;
    protected:
        void data() const{
            std::cout << "Draw time:" << time << std::endl;
            std::cout << "Gun Notches: " << notches << std::endl;
        }
        void input() {
            std::cout << "Please enter Gunslinger draw time:";
            std::cin >> time;
            std::cout << "Please enter Gunslinger notches:";
            std::cin >> notches;
        }
    public:
        Gunslinger(const Person &p, double t, int n) : Person
        (p), time(t), notches(n) {}

        Gunslinger(const std::string &first = "noname", const std::string &last = "noname", double t  = 0.0, int n = 0) : Person(first, last), time(t), notches(n){}

        double Draw() const {return time;}
        void Show() const {
            std::cout << "GunsLinger" << std::endl;
            Person::data();
            data();
            std::cout << "Gunslinger do draw with time:" << Draw() << std::endl;
        }
        void Set() {
            Person::input();
            input();
        }
};

class PokerPlayer : public virtual Person {
    public:
        PokerPlayer(const std::string &first = "noname", const std::string &last = "noname") : Person(first, last) {}
        PokerPlayer(const Person &p) :  Person(p) {} 
        int Draw() const {
            srand(time(0));
            return rand() % 52 + 1;
        }
        void Show() const {
            std::cout << "PokerPlayer" << std::endl;
            Person::data();
            std::cout << "PokerPlayer do draw with card:" << Draw() << std::endl;
        }
        void Set() {
            Person:input();
        }
};

class BadDude : public Gunslinger, public PokerPlayer {
    public:
        BadDude(const std::string &first = "noname", const std::string &last = "noname", double t = 0.0, int n = 0) : Person(first, last), Gunslinger(first, last, t, n){}    
        BadDude(const Person &p, double t, int n) : Person(p), PokerPlayer(p), Gunslinger(p, t, n) {}

        double Gdraw() const{
            return Gunslinger::Draw();
        }

        int Cdraw() const {
            return PokerPlayer::Draw();
        }

        void Show() const{
            std::cout << "BadDue" << std::endl;
            Person::data();
            Gunslinger::data();
            std::cout << "BadDude do draw gun with time:" << Gdraw() << std::endl;
            std::cout << "BadDude do draw card:" << Cdraw() << std::endl;
        }

        void Set() {
            Person::input();
            Gunslinger::input();
        }
};

#endif