#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "QueueTp.h"

const int MIN_PER_HR = 60;

class Customer {
    private:
        long arrive;
        int processtime;
    public:
        Customer() {arrive = processtime = 0;}
        void set(long when);
        long when() const {return arrive;}
        int ptime() const {return processtime;}
};

void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}

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
    cout << "Enter how many ATM do you want: ";
    int num_ATM;
    cin >> num_ATM;

    Queue<Customer> *lines = new Queue<Customer>[num_ATM]{qs};

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Customer temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int  *wait_times = new int[num_ATM]{0};
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            Queue<Customer> *smallestLine = nullptr;
            for (int i = 0; i < num_ATM; i++) {
                if (!lines[i].isfull()) {
                    if (nullptr == smallestLine){
                        smallestLine = &lines[i];
                    } else {
                        if (lines[i].queuecount() < smallestLine->queuecount()) {
                            smallestLine = &lines[i];
                        }
                    }
                }
            }

            if (nullptr == smallestLine) {
                turnaways++;
            } else {
                customers++;
                temp.set(cycle);
                smallestLine->enqueue(temp);
            }
        }
        for (int i = 0 ; i < num_ATM; i++){
            if (wait_times[i] <= 0 && !lines[i].isempty()) {
                lines[i].dequeue(temp);
                wait_times[i] = temp.ptime();
                line_wait += cycle- temp.when();
                served++;
            }
        }

        for (int i = 0; i < num_ATM; i++) {
            if (wait_times[i] > 0){
                wait_times[i]--;
            }
        }
        
        for (int i = 0; i < num_ATM; i++) {
            sum_line += lines[i].queuecount();
        }
    }

    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers server: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit /num_ATM << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";    
    } else {
        cout << "No customers!\n";
    }

    cout << "Done!\n";

    return 0;
}