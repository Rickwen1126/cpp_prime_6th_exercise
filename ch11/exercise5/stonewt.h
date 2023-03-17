#ifndef STONEWT_H
#define STONEWT_H
#include <iostream>

class Stonewt {
    private: 
        enum {Lbs_per_stn = 14};
        enum Mode{MODE_ST, MODE_INT, MODE_FLOAT};
        int stone;
        double pds_left;
        double pounds;
        Mode mode;
    public:
        Stonewt(double lbs, Mode form = MODE_ST);
        Stonewt(int stn, double lbs, Mode form = MODE_ST);
        Stonewt();
        ~Stonewt();
        Stonewt operator+(const Stonewt &other) const;
        Stonewt operator-(const Stonewt &other) const;
        Stonewt operator*(const Stonewt &other) const;
        Stonewt operator*(double val) const;
        // conversion function
        operator int() const;
        operator double() const;
        friend Stonewt operator*(const Stonewt &s1, const Stonewt &s2);
        friend Stonewt operator*(double mult, const Stonewt &s2);
        friend std::ostream &operator<<(std::ostream &os, const Stonewt &st);
};

#endif
