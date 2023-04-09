#include "exercise1.h"

int main(int argc, char *argv[]) {
    {
        Cow c1;
        Cow c2("cow1", "fat", 100);
        Cow c3(c2);
        Cow c4;
        c4 = c2;

        c1.ShowCow();
        c2.ShowCow();
        c3.ShowCow();
        c4.ShowCow();
    }

    return 0;
}