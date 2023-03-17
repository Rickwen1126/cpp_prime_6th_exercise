#include "stonewt.h"
#include <iostream>


Stonewt::Stonewt(double lbs, Mode form) {
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = form;
}

Stonewt::Stonewt(int stn, double lbs, Mode form) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = form;
}

Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {

}

// void Stonewt::show_stn() const {
//     switch (mode) {
//         case MODE_ST:
//             std::cout << stone << " stone, " << pds_left << " pounds\n";        
//             break;
//     }
//     std::cout << stone << " stone, " << pds_left << " pounds\n";
// }

// void Stonewt::show_lbs() const {
//     std::cout << pounds << " pounds\n";
// }

std::ostream & operator<<(std::ostream &os, const Stonewt &st) {
    switch (st.mode) {
        case Stonewt::MODE_ST:
            os << st.stone << " stone\n";
            break;
        case Stonewt::MODE_INT:
            os << (int)st.pounds + 0.5 << " pounds\n";
            break;
        case Stonewt::MODE_FLOAT:
            os << st.pounds << " pounds\n";
            break;
    }
}

Stonewt Stonewt::operator+(const Stonewt &other) const {
    return Stonewt(pounds + other.pounds);
}

Stonewt Stonewt::operator-(const Stonewt &other) const {
    return Stonewt(pounds - other.pounds);
}

Stonewt Stonewt::operator*(const Stonewt &other) const {
    return Stonewt(pounds * other.pounds);
}

Stonewt::operator int() const {
    return int (pounds + 0.5);
}

Stonewt::operator double() const {
    return pounds;
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

