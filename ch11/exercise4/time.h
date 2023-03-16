#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class Time {
    private:
        int hours;
        int minutes;
    public:
        Time(int h = 0, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        // Time operator+(const Time &t) const;
        // Time operator-(const Time &t) const;
        // Time operator*(double n) const;

        friend Time operator+(const Time &t1, const Time &t2);
        friend Time operator-(const Time &t1, const Time &t2);
        friend Time operator*(const Time &t1, double m);
        friend Time operator*(double m, const Time &t)
        {
            return t * m;
        } // inline definition
        friend std::ostream &operator<<(std::ostream &os, const Time &t);
};

#endif