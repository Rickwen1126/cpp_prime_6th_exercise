// #include "exercise1.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>

// class S {
//     public:
//         S() {
//             std::cout << "base constructor" << std::endl;
//         }

//         virtual void f() {
//             std::cout << "base S" << std::endl;
//         };

// };
// class T : public S {
//     public:
//         virtual void f() {
//             std::cout << "derived T" << std::endl;
//         }
// };

using namespace std;

class S {
    private:
        void pri() {
            cout << "private base function" << endl;
        }
        string str;
    public:
        virtual void f() {
            std::cout << "public base" << std::endl;
        }
        void f2(){
            std::cout << "public base 2" << std::endl;
        }
    protected:
        void pro() {
            cout << "protected base" << endl;
        }
        
};

class T : S {
    public:
    void f() {
        std::cout << "derived" << std::endl;
        f2();
        pro();
    }  
};

int main(int argc, char *argv[]) {
    T t;

    t.f();

    return 0;
}