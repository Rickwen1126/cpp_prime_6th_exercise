#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error {
    public:
        bad_hmean(const std::string &s) : std::logic_error(s) {}
        const char * what() const noexcept {
            return "invalid arguments: a = -b\n";
        }
        
};

class bad_gmean : public std::logic_error {
    public:
        bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        const char *mesg();
};

inline const char * bad_gmean::mesg() {
    return "gmean() arguments should be >= 0\n";
}