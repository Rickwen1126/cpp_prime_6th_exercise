//  golf.cpp --for sol-9-01.cpp

#include "golf.h"
#include <iostream>
#include <cstring>

golf::golf(const char *name, int hc){
    strncpy(fullname, name, Len - 1);

    if (fullname[Len - 1] != '\0')
        fullname[Len - 1] = '\0';

    handicap = hc;
} 

int golf::setGolf() {
    std::cout << "Enter full name: ";
    char tmpName[Len];
    std::cin.get(tmpName, Len);
    if (tmpName[0] == '\0')
    {
        std::cin.clear();
        return 0;
    }
    while (std::cin.get() != '\n')
        continue;

    int tmpHc;
    std::cout << "Enter handicap: ";
    (std::cin >> tmpHc).get();

    golf tmpGolf(tmpName, tmpHc);
    *this = tmpGolf;

    return 1;
}

int setgolf(golf &g)
{
    std::cout << "Enter full name: ";
    char tmp[Len];
    std::cin.get(tmp, Len);
    if (tmp[0] == '\0')
    {
        std::cin.clear();
        return 0;
    }
    while (std::cin.get() != '\n')
        continue;
    // strcpy(g.fullname, tmp);
    // std::cout << "Enter handicap: ";
    // (std::cin >> g.handicap).get();
    return 1;
}
void golf::setHandicap(int hc)
{
    this->handicap = hc;
}
void golf::showGolf() const 
{
    std::cout << "Name: " << fullname
              << "\nhandicap: " << handicap << std::endl;
}