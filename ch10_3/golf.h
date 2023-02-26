//  golf.h --for sol-9-01.cpp

#ifndef GOLF_H_
#define GOLF_H_

const int Len = 40;
struct golf
{
    golf(const char * name ="\0", int hc = 0);
    void setHandicap(int hc);
    void showGolf() const;
    int setGolf();

private:
    char fullname[Len];
    int handicap;
};

int setgolf(golf &g);

#endif