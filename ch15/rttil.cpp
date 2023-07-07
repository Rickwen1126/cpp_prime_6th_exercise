#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

class Grand {
    private:
        int hold;
    public:
        Grand(int h = 0) : hold(h) {}
        virtual void Speak() const {cout << "I am a grand class!\n";}
        virtual int Value()
};