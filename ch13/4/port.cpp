#include "port.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b) {
    size_t brLen = strlen(br) + 1;
    brand = new char[brLen];
    strncpy(brand, br, brLen);
    strncpy(style, st, 20);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port &p) {
    size_t brLen = strlen(p.brand) + 1;
    delete [] brand;
    brand = new char[brLen];
    strncpy(brand, p.brand, brLen);
    strncpy(style, p.style, 20);
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p) {
    if (this == &p) {
        return *this;
    }

    delete [] brand;
    size_t brLen = strlen(p.brand) + 1;
    brand = new char[brLen];
    strncpy(brand, p.brand, brLen);
    strncpy(style, p.style, 20);
    bottles = p.bottles;

    return *this;
}

Port& Port::operator+=(int b) {
    bottles += b;

    return *this;
}

Port& Port::operator-=(int b) {
    bottles -= b;

    return *this;
}

void Port::Show() const {
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p) {
    os << p.brand << ", "<< p.style << ", " <<  p.bottles;

    return os;
}

VintagePort::VintagePort() : Port("none", "vintage") {
    nickname = new char[1]{'\0'};
    year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b) {
    size_t nameSize = strlen(nn) + 1;
    nickname = new char[nameSize];
    strncpy(nickname, nn, nameSize);
    nickname[nameSize - 1] = '\0';
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp){
    delete [] nickname;
    size_t nameSize = strlen(vp.nickname) + 1;
    nickname = new char[nameSize];
    strncpy(nickname, vp.nickname, nameSize);
    year = vp.year;   
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
    if (this == &vp) {
        return *this;
    }


    Port::operator=(vp);

    delete [] nickname;
    size_t nameSize = strlen(vp.nickname) + 1;
    nickname = new char[nameSize];
    strncpy(nickname, vp.nickname, nameSize);
    year = vp.year; 

    return *this;
}

void VintagePort::Show() const{
    Port::Show();
    cout << "Nick name: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream &operator<<(ostream &os, const VintagePort &vp) {
    os << (Port&)vp << ", " << vp.nickname << ", " << vp.year;

    return os;
}