#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));
    cout << "Case Study : Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int  wait_time = 0;
    long line_wait = 0;
    long leave_self = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if(line.isfull()) {
                turnaways++;
            } else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }

        // check if customer does't want to wait more than one minute
        for (int i = 0; i < line.queuecount(); i++) {
            if (cycle - line[i].when() > 1) {
                leave_self++;
                line.deleteNodeByIdx(i);
            }
        }

        if (wait_time <= 0 && !line.isempty()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }

        if (wait_time > 0){
            wait_time--;
        }

        sum_line += line.queuecount();
    }

    if (customers > 0) {
        cout << " customers accepted: " << customers << endl;
        cout << "   customers server: " << served << endl;
        cout << "          turnaways: " << turnaways << endl;
        cout << "does't want to wait: " << leave_self << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";    
    } else {
        cout << "No customers!\n";
    }

    cout << "Done!\n";

    return 0;
}