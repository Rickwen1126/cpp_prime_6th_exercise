#include "stock.h"
#include <cstring>
#include <iostream>


Stock::Stock() {
    const char *defaultCo = "no company";
    company = new char[11];
    std::strcpy(company, defaultCo);
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *co, long n, double pr) {
    int len = std::strlen(co);
    company = new char[len + 1];
    std::strcpy(company, co);

    if (n < 0) {
        std:: cout << "Number of shares can't be negative; "
                    << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock() {
    delete []company;
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares purchased can not be negative. "
        << "Transaction is aborted\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using std::cout;
    if (num < 0){
        cout << "Number of shares sold can not be negative. "
          << "Transaction is aborted.\n";
    } else if (num > shares) {
        cout << "You can not sell more than you have! "
             << "Transaction is aborted. \n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() const {
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "company: " << company 
         << " Shares: " << shares << '\n';
    cout << " Share price: $" << total_val << '\n';

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock &Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val) {
        return s;
    } else {
        return  *this;
    }
}

std::ostream& operator<<(std::ostream &os, const Stock &st) {
    using std::ios_base;
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);
    os << "company: " << st.company 
         << " Shares: " << st.shares << '\n';
    os << " Share price: $" << st.total_val << '\n';

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);


    return os;
}