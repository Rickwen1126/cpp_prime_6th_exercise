#include<iostream>
using namespace std;

class B{
    public:
         virtual B& operator=(const B& right) {
            x = right.x;
            return *this;
        }
        int x;
};

class D : public B {
    public:
         D& operator=(const D& right) {
            y = right.x;
            y = right.y;
            return *this;
        }

        virtual D& operator=(const B& right) {
            x = right.x;
            y = 0;
            return *this;
        }

        int y;
};


int main() {
    D d1;
    B &br1 = d1;
    d1.x = 99;
    d1.y = 100;
    cout << d1.x << ", " << d1.y << endl;

    B b1(br1);
    b1.x = 133;

    D d2;
    B &br2 = d2;
    d2.x = 3;
    d2.y = 2;
    br2 = br1; 
    cout << d2.x << ", " << d2.y << endl;

    return 0;
}