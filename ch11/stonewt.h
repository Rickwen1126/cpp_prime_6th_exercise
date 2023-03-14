#ifndef STONEWT_H
#define STONEWT_H

class Stonewt {
    private: 
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        void show_lbs() const;
        void show_stn() const;
        Stonewt operator*(double val) const;
        // conversion function
        operator int() const;
        operator double() const;
        friend Stonewt operator*(const Stonewt &s1, const Stonewt &s2);
        friend Stonewt operator*(double mult, const Stonewt &s2);
};

#endif
