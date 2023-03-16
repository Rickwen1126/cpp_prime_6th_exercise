#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>

namespace VECTOR {
    class Vector {
        public:
            enum Mode {RECT, POL};
        private:
            double x;
            double y;
            // double mag;
            // double ang;
            Mode mode;
            // void set_mag();
            // void set_ang();
            void set_x();
            void set_y();
            void set_val(double n1, double n2, Mode form);
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double xval() const {return x;};
            double yval() const {return y;};
            double magval() const {
                return sqrt(x * x + y * y);
            };
            double angval() const {
                double ang;
                if (x == 0.0 && y == 0.0)
                {
                    ang = 0.0;
                }
                else
                {
                    ang = atan2(y, x);
                }
                return ang;
            };
            void polar_mode();
            void rect_mode();
            Vector operator+(const Vector &b) const;
            Vector operator-(const Vector &b) const;
            Vector operator-() const;
            Vector operator*(double n) const;
            bool operator>(const Vector &other) const;

            // friend functions
            friend Vector operator*(double n , const Vector &a);
            friend std::ostream& operator<<(std::ostream &os, const Vector &v);

            // conversion functions
            operator double();
    };
}

#endif