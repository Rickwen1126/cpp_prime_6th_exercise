#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace VECTOR;
    using std::endl;
    std::ofstream cout("test.out");
    double target = 50;
    double dstep = 10;
    double direction;
    srand(time(0)); // seed random-number generator double direction;
    Vector vStep;
    Vector result(0.0, 0.0);
    long stepCount = 0;
    long 

    if (argc >= 3)
    {
        target = std::stod(argv[1]);
        dstep = std::stod(argv[2]);
    }

    cout << "Taget distance: " << target << ", "
              << "Step Size: " << dstep << endl;

    while (result.magval() < target)
    {
        cout << stepCount << ": " << result << endl;
        direction = rand() % 360;
        vStep.reset(dstep, direction, Vector::POL);
        result = result + vStep;
        stepCount++;
    }
    cout << "After " << stepCount << " steps, the subject "
                                     "has the following location:\n";
    cout << result << endl;
    result.polar_mode();
    cout << " or\n"
         << result << endl;
    cout << "Average outward distance per step = "
         << result.magval() / stepCount << endl;

    return 0;
}
