#include "exercise1.h"
#include <cstring>
#include <iostream>

int Cow::count = 0;

Cow::Cow() {
    hobby = new char[1]{'\0'};
    weight = 0;
    Cow::count++;
    std::cout << "Total Cows count:" << count << std::endl;
}

Cow::Cow(const char *nm, const char *ho, double wt){
    weight = wt;
    std::strcpy(name, nm);
    auto len = strlen(ho);
    hobby = new char[len + 1];
    std::strcpy(hobby, ho);
    Cow::count++;
    std::cout << "Total Cows count:" << count << std::endl;
}

Cow::Cow(const Cow &c) {
    weight = c.weight;
    std::strcpy(name, c.name);
    auto len = strlen(c.hobby);
    hobby = new char[len + 1];
    std::strcpy(hobby, c.hobby);
    Cow::count++;
    std::cout << "Total Cows count:" << count << std::endl;
}

Cow::~Cow() {
    delete []hobby;
    Cow::count--;
    std::cout << "Total Cows count:" << count << std::endl;   
}

Cow& Cow::operator=(const Cow &c) {
    if (this == &c) {
        return *this;
    }

    delete []hobby;
    std::strcpy(name, c.name);
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    std::strcpy(hobby, c.hobby);

    return *this;
}

void Cow::ShowCow() const {
    std::cout << "Cow Name:" << name << std::endl;
    std::cout << "Cow hobby:" << hobby << std::endl;
    std::cout << "Cow weight:" << weight << std::endl;
}