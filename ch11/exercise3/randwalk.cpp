//  --------------------- S.Prata C++ Primer Plus 6th ed. ----------------------
//  ----------------------- Programming Exercises 11.2 -------------------------

#include "vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>

int main(void)
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    unsigned long maxSteps = 0, minSteps = INT_MAX, totalSteps = 0;
    unsigned long round = 0; 
    unsigned long trialTimes = 1;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while(cin >> target)
    {
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;
        cout << "Enter trial times: ";
        if(!(cin >> trialTimes))
            break;
        round++;
        while (trialTimes--)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }

            if (steps > maxSteps)
            {
                maxSteps = steps;
            }

            if (steps < minSteps)
            {
                minSteps = steps;
            }

            totalSteps += steps;

            cout << "After " << steps << " steps, the subject "
                                         "has the following location:\n";
            cout << result << endl;
            result.polar_mode();
            cout << " or\n"
                 << result << endl;
            cout << "Average outward distance per step = "
                 << result.magval() / steps << endl;

            cout << "Max steps = " << maxSteps << endl;
            cout << "Min steps = " << minSteps << endl;
            cout << "Avg steps = " << totalSteps / round << endl;

            steps = 0;
            result.reset(0.0, 0.0);
        }
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n')
        continue;
    return 0;
}