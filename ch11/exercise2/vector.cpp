#include <cmath>
#include "vector.h"

using std::cout;
namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);
    // void Vector::set_mag() {
    //     mag = sqrt(x*x + y*y);
    // }

    // void Vector::set_ang() {
    //     if (x == 0.0 && y == 0.0) {
    //         ang = 0.0;
    //     } else {
    //         ang = atan2(y, x);
    //     }
    // }

    // void Vector::set_x() {
    //     x = mag * cos(ang);
    // }  

    // void Vector::set_y() {
    //     y = mag * sin(ang);
    // } 

    void Vector::set_val(double n1, double n2, Mode form) {
        mode = form;

        if (mode == RECT) {
            x = n1;
            y = n2;
        } else if (form == POL) {
            x = n1 * cos(n2);
            y = n1 * sin(n2);           
        } else {
            cout << "Incorrect 3rd argument to Vector --";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::Vector() {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form) {
       set_val(n1, n2, form);
    }

    void Vector::reset(double n1, double n2, Mode form) {
       set_val(n1, n2, form);
    }

    Vector::~Vector() {

    }

    void Vector::polar_mode() {
        mode = POL;
    }

    void Vector::rect_mode() {
        mode = RECT;
    }

    bool Vector::operator>(const Vector &other) const {
        return magval() > other.magval();
    }

    Vector Vector::operator+(const Vector &b) const {
        return Vector(x+b.x, y+b.y);
    }

    Vector Vector::operator-(const Vector &b) const {
        return Vector(x-b.x, y-b.y);
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const {
        return Vector(x * n, y * n);
    }

    Vector operator*(double n, const Vector &a) {
        return Vector(n * a.x, n * a.y);
    }

    Vector::operator double(){
        return magval();
    }

    std::ostream & operator<<(std::ostream &os, const Vector &v){
        if (v.mode == Vector::RECT) {
            os << "(x,y) = (" <<  v.x << ", " << v.y << ")";
        } else if (v.mode == Vector::POL) {
           os << "(m,a) = (" << v.magval() << ", " << v.magval() * Rad_to_deg << ")";
        } else {
            os << "Vector object mode is invalid";
        }

        return os;
    }
}