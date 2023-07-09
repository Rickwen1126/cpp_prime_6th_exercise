#include <iostream>
#include <stdexcept>

class bad_mean : public std::logic_error {
    protected:
        double a;
        double b;
    public:
        bad_mean(double a, double b) : logic_error(""), a(a), b(b) {}
        virtual const char* what() {
            return "bad_mean(): base mean called!";
        }
        virtual void report() const = 0;
};

class bad_hmean : public bad_mean
{
    public:
        bad_hmean(double a, double b) : bad_mean(a, b) {}
        const char * what() {
            return "bad_hmean(): invalid arguments: a = -b\n";
        }

        virtual void report() const {
            std::cout << "bad_hmean() with a = " << a << " and b = " << b;
        } 
};

class bad_gmean : public bad_mean
{
    public:
        bad_gmean(double a, double b) : bad_mean(a, b) {}
        const char *what(){
            return "bad_gmean(): arguments should be >= 0\n";
        }

        virtual void report() const
        {
            std::cout << "bad_gmean() with a = " << a << " and b = " << b;
        }
};