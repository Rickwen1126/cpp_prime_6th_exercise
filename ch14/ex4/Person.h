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
    public:
        Gunslinger(const Person &p, double t, int n) : Person(p), time(t), notches(n) {}
        double Draw() const {return time;}
        void Show() const {
            std::cout << "GunsLinger" << std::endl;
            Person::data();
            data();
        } 
};

class PokerPlayer : public virtual Person {
    public:
        PokerPlayer(const Person &p) :  Person(p) {} 
        int Draw() const {
            srand(time(0));
            return rand() % 52 + 1;
        }
        void Show() const {
            std::cout << "PokerPlayer" << std::endl;
            Person::data();
        }
};

class BadDude : public Gunslinger, public PokerPlayer {
    public:
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
        }
};

#endif