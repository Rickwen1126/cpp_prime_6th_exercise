#include "emp.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

abstr_emp::abstr_emp() {}

abstr_emp::abstr_emp(const std::string &fn, const std::string & ln, const std::string &j) : fname(fn), lname(ln), job(j) {}

abstr_emp::abstr_emp(const abstr_emp &ot) : fname(ot.fname), lname(ot.lname), job(ot.job) {}

abstr_emp::~abstr_emp() {}

void abstr_emp::data() const{
    cout << "first name: " << fname << endl;
    cout << "last name: " << lname << endl;
    cout << "job: " << job << endl;
}

void abstr_emp::input() {
    cout << "Please enter frst name: ";
    cin >> fname;
    cout << "Please enter last name: ";
    cin >> lname;
    cout << "Please enter job: ";
    cin >> job;
}

void abstr_emp::ShowAll() const {
    data();
}

void abstr_emp::SetAll() {
    input();
}

// friend function
std::ostream & operator<<(std::ostream &os, const abstr_emp &e) {
    os << e.fname << " " << e.lname;

    return os;
}

//*************employee**************

employee::employee() {}

employee::employee(const std::string &fn, const std::string &ln,  const std::string &j) : abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
    abstr_emp::ShowAll();
}

void employee::SetAll() {
    abstr_emp::SetAll();

}

//*************employee**************

manager::manager() {}

manager::manager(const std::string &fn, const std::string &ln, const std::string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico){}

manager::manager(const manager &m) : abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::data() const {
    std::cout << "incharge of:" << InChargeOf() << std::endl;    
}

void manager::input() {
    std::cout << "Please enter incharge of:";
    std::cin >> inchargeof;
}

void manager::ShowAll() const {
    abstr_emp::data();
    data();
}

void manager::SetAll() {
    abstr_emp::input();
    input();
}

/******************fink***********************/
    

fink::fink(){}

fink::fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const std::string &rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &ot) : abstr_emp(ot), reportsto(ot.reportsto) {}

void fink::data() const{
    std::cout << "reportsto:" << reportsto << std::endl; 
}

void fink::input() {
    std::cout << "Please enter repoters to:";
    std::cin >> reportsto;
}

void fink::ShowAll() const{
    abstr_emp::data();
    data();
}

void fink::SetAll() {
    abstr_emp::input();
    input();
}

/*******************highfink************************/

highfink::highfink(){}

highfink::highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico) : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)  {}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico) : abstr_emp(e), fink(e, rpo), manager(e, ico) {} 


highfink::highfink(const manager &m, const std::string &rpo) : abstr_emp(m), manager(m), fink(m,rpo) {}
highfink::highfink(const highfink &h) : abstr_emp(h), fink(h), manager(h) {}

void highfink::ShowAll() const {
    abstr_emp::data();
    fink::data();
    manager::data();
}
void highfink::SetAll() {
    abstr_emp::input();
    fink::input();
    manager::input();
}