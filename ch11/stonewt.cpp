#include "stonewt.h"
#include <iostream>


Stonewt::Stonewt(double lbs) {
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {

}

void Stonewt::show_stn() const {
    std::cout << stone << " stone, " << pds_left << " pounds\n";
}

Stonewt Stonewt::operator*(double val) const {
    return Stonewt(val * pounds);
}

Stonewt operator*(const Stonewt &s1, const Stonewt &s2)
{
    return Stonewt(s1.pounds * s2.pounds);
}

Stonewt operator*(double mult, const Stonewt &s2) {
    return Stonewt(mult * s2.pounds);
}

// void Stonewt::
