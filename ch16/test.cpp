#include <vector>
#include <iostream>
#include "iter.h"
#include <iterator>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <string>


//chapter review ch16, ex1
class RQ1 {
    private:
        std::string st;
    public:
        RQ1(){};
        RQ1(const char *s): st(s){}
};

void removeSpace(std::string &s) {
    int slow = 0;
    int fast = 0;
    while(fast <= s.size()) {
        if(s[fast] != ' ') {
            // if (slow != 0) s[slow++] = ' ';
            while(fast < s.size() && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
        }

        fast++;        
    }

    s.resize(slow);
}

void outint(int n) {std::cout << n << " ";}

template<class TT>
class Gala {
    private:
        TT val;
        static int ct;
    public:
        Gala(TT v) : val(v) {ct++;}

        template<class X>
        friend void counts();

        template<class Y>
        friend void reports(const Y&);
};

template<class TT>
int Gala<TT>::ct = 0;

template<class X>
void counts() {
    std::cout << X::ct << std::endl;
}

template<class Y>
void reports(const Y& y) {
    std::cout << y.val << std::endl;
}


template<class T>
class Out {
    public:
    void operator()(T val) {
        std::cout << val << std::endl;
    }
};

void uppercase(std::string &s) {
     std::transform(s.begin(), s.end(), s.begin(), toupper);
}

template<class T>
class TooBig{
    private:
        T cutoff;
    public:
        TooBig(const T & t) : cutoff(t) {}
        bool operator()(const T &v) {return v > cutoff;}
};

int main() {
    using namespace std;

    string s("abhghj");

    uppercase(s);
    
    cout << TooBig<int>(10)(15);


    // reports<Gala<double>>(g1);


    // list<int> one(5, 2);
    // int stuff[5] = {1, 2, 4, 8, 6};
    // list<int> two;
    // two.insert(two.begin(), stuff, stuff+5); 
    // int more[6] = {6, 4, 2, 4, 6, 5};
    // list<int> three(two);
    // three.insert(three.end(), more, more + 6); 

    // cout << "List one: ";
    // for_each(one.begin(), one.end(), outint);

    // cout << endl << "List two: ";
    // for_each(two.begin(), two.end(), outint);

    // cout << endl << "List three: ";
    // for_each(three.begin(), three.end(), outint);
    // three.remove(2);

    // cout << endl << "List three minus 2s: ";
    // for_each(three.begin(), three.end(), outint);
    // three.splice(three.begin(), one);
    // cout << endl << "List three after splice: ";
    // for_each(three.begin(), three.end(), outint);
    // three.sort();
    // three.unique();
    // cout << endl << "List three after sort & unique: ";
    // for_each(three.begin(), three.end(), outint);
    // two.sort();
    // three.splice(three.begin() ,two);
    // cout << endl << "Sorted two merged int three: ";
    // for_each(three.begin(), three.end(), outint);
    // cout << endl;
    // cout << endl << "Sorted two merged int two: ";
    // for_each(two.begin(), two.end(), outint);

    


    
    // vector<int> old_v{1, 2, 3, 4};
    // vector<int> new_v{5,6,7,8};
    // vector<int> gala(new_v.begin(), new_v.end()-1);
    // list<int> la{8, 10, 3, 4, 5,10, 9,9,9,10,10,10,10};
    // list<int> lb{7, 8, 6, 1, 8 ,9};

    // // la.merge(lb);

    // ostream_iterator<int, char> out_iter(cout, " ");
    
    
    
    // // la.remove(10);

    // // la.splice(++la.begin(), lb);
    // la.unique();

    // copy(la.begin(), la.end(), out_iter);oooo

    // auto iter = Find(arr, arr+4, 5);


    // if (iter != arr+4) {
    //     cout << *iter;
    // } else {
    //     cout << "not find";
    // }

    // copy(istream_iterator<int, char>(cin), istream_iterator<int ,char>(cin), old_v.begin());
    // copy(old_v.rbegin(), old_v.rend(), ostream_iterator<int, char>(cout, " "));
    // vector<int>::iterator iter;
    // for (iter = old_v.rbegin() ; iter != old_v.rend(); iter++) {
    //     cout << *iter << " ";
    // }

    
    
    // copy(gala.begin(), gala.end(), ostream_iterator<int, char>(cout, " "));

   
    return 0;
}