#include "emp.h"
#include <iostream>
#include <cstring>
#include <sstream>

#define DATA_SEP ' '
#define DATA_ROW_FNAME "fname="
#define DATA_ROW_LNAME "lname="
#define DATA_ROW_JOB "job="
#define DATA_ROW_IN_CHARGE_OF "in_charge_of="
#define DATA_ROW_REPRTSTO "reportsto="

using std::cout;
using std::cin;
using std::endl;

size_t getKeyWordLastPos(const std::string &s, const char *key) {
    size_t pos = s.find(key);
    if (pos == std::string::npos) {
        std::cerr << "can not find " << key;
        return std::string::npos;
    }

    pos += std::strlen(key);

    return pos;
}
void readTillSep(const std::string &src, std::string &target, size_t startPos, const char sep) {
    while(src[startPos] != sep) {
        target += src[startPos++];
    }
}

abstr_emp::abstr_emp() {}

abstr_emp::abstr_emp(const std::string &fn, const std::string & ln, const std::string &j) : fname(fn), lname(ln), job(j) {}

abstr_emp::abstr_emp(const std::string &fileString) {
    size_t pos = getKeyWordLastPos(fileString, DATA_ROW_FNAME);
    if (pos == std::string::npos) {
        return;
    }
    readTillSep(fileString, fname, pos, DATA_SEP);
    pos = getKeyWordLastPos(fileString, DATA_ROW_LNAME);
    if (pos == std::string::npos) {
        return;
    }
    readTillSep(fileString, lname, pos, DATA_SEP);
    pos = getKeyWordLastPos(fileString, DATA_ROW_JOB);
    if (pos == std::string::npos) {
        return;
    }
    readTillSep(fileString, job, pos, DATA_SEP);
}

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

void abstr_emp::write(std::ofstream &fout) {
    fout << DATA_ROW_FNAME << fname << DATA_SEP << DATA_ROW_LNAME << lname << DATA_SEP << DATA_ROW_JOB << job << DATA_SEP;    
}

void abstr_emp::writeClassMark(std::ofstream &fout, const char mark) {
    fout << CLASS_PREFIX << mark << DATA_SEP;
}

void abstr_emp::ShowAll() const {
    data();
}

void abstr_emp::SetAll() {
    input();
}

void abstr_emp::WriteAll(std::ofstream &fout) {
    writeClassMark(fout, CLASS_ABS);
    write(fout);
    fout << endl;
}

// friend function
std::ostream & operator<<(std::ostream &os, const abstr_emp &e) {
    os << e.fname << " " << e.lname;

    return os;
}

//*************employee**************

employee::employee() {}

employee::employee(const std::string &fn, const std::string &ln,  const std::string &j) : abstr_emp(fn, ln, j) {}

employee::employee(const std::string &fileString) : abstr_emp(fileString) {}

void employee::ShowAll() const {
    cout << "Empolyee:" << endl;
    abstr_emp::ShowAll();
}

void employee::SetAll() {
    abstr_emp::SetAll();
}

void employee::WriteAll(std::ofstream &fout) {
    writeClassMark(fout, CLASS_EMP);
    abstr_emp::write(fout);
    fout << std::endl;
}

//*************employee**************

manager::manager() {}

manager::manager(const std::string &fn, const std::string &ln, const std::string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico) {}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico){}

manager::manager(const manager &m) : abstr_emp(m), inchargeof(m.inchargeof) {}

manager::manager(const std::string &fileString) : abstr_emp(fileString) {
    auto pos = getKeyWordLastPos(fileString, DATA_ROW_IN_CHARGE_OF);
    if (pos == std::string::npos) return;
    std::string inChargeOfStr;
    readTillSep(fileString, inChargeOfStr, pos, DATA_SEP);
    inchargeof = std::stoi(inChargeOfStr);
}

void manager::data() const {
    std::cout << "incharge of:" << InChargeOf() << std::endl;    
}

void manager::input() {
    std::cout << "Please enter incharge of:";
    std::cin >> inchargeof;
}

void manager::write(std::ofstream &fout) {
    fout << DATA_ROW_IN_CHARGE_OF << inchargeof << DATA_SEP;
}

void manager::ShowAll() const {
    cout << "Manager:" << endl;
    abstr_emp::data();
    data();
}

void manager::SetAll() {
    abstr_emp::input();
    input();
}

void manager::WriteAll(std::ofstream &fout) {
    abstr_emp::writeClassMark(fout, CLASS_MGR);
    abstr_emp::write(fout);
    write(fout);
    fout << endl;
}

/******************fink***********************/
    

fink::fink(){}

fink::fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp &e, const std::string &rpo) : abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink &ot) : abstr_emp(ot), reportsto(ot.reportsto) {}

fink::fink(const std::string &fileString) : abstr_emp(fileString) {
    auto pos = getKeyWordLastPos(fileString, DATA_ROW_REPRTSTO);

    if (pos ==  std::string::npos) return;

    readTillSep(fileString, reportsto, pos, DATA_SEP);
}

void fink::data() const{
    std::cout << "reportsto:" << reportsto << std::endl; 
}

void fink::write(std::ofstream &fout) {
    fout << DATA_ROW_REPRTSTO << reportsto << DATA_SEP;
}

void fink::input() {
    std::cout << "Please enter repoters to:";
    std::cin >> reportsto;
}

void fink::ShowAll() const{
    cout << "Fink:" << endl;
    abstr_emp::data();
    data();
}

void fink::SetAll() {
    abstr_emp::input();
    input();
}

void fink::WriteAll(std::ofstream &fout) {
    abstr_emp::writeClassMark(fout, CLASS_FINK);
    abstr_emp::write(fout);
    write(fout);
    fout << endl;
}

/*******************highfink************************/

highfink::highfink(){}

highfink::highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico) : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)  {}

highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico) : abstr_emp(e), fink(e, rpo), manager(e, ico) {} 


highfink::highfink(const manager &m, const std::string &rpo) : abstr_emp(m), manager(m), fink(m,rpo) {}
highfink::highfink(const highfink &h) : abstr_emp(h), fink(h), manager(h) {}

highfink::highfink(const std::string &fileString) : abstr_emp(fileString), fink(fileString),  manager(fileString) {
}

void highfink::ShowAll() const {
    cout << "HighFink:" << endl;
    abstr_emp::data();
    fink::data();
    manager::data();
}
void highfink::SetAll() {
    abstr_emp::input();
    fink::input();
    manager::input();
}

void highfink::WriteAll(std::ofstream &fout) {
    abstr_emp::writeClassMark(fout, CLASS_HIGH);
    abstr_emp::write(fout);
    fink::write(fout);
    manager::write(fout);
    fout << endl;
}