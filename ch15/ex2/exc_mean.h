#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error {
    public:
        bad_hmean(const std::string &s = "bad_hmean(): invalid arguments: a = -b\n") : std::logic_error(s) {}
};

class bad_gmean : public std::logic_error {
    public:
        bad_gmean(const std::string &s = "bad_gmean(): arguments should be >= 0\n") : std::logic_error(s) {}
};