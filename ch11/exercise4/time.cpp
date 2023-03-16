#include "time.h"
Time::Time(int h, int m):hours(h), minutes(m) {

}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m){
    minutes = m;
    hours = h;
}

Time operator+(const Time &t1, const Time&t2) {
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes = sum.minutes % 60; 
    return sum;
}

Time operator-(const Time &t1, const Time&t2) {
    Time diff;
    int t1TotalMinutes = t1.minutes + t1.hours * 60;
    int t2TotalMinutes = t2.minutes + t2.hours * 60; 
    int totalDiff = t1TotalMinutes - t2TotalMinutes;
    diff.minutes = totalDiff % 60;
    diff.hours = totalDiff / 60;
    return diff;
}

Time operator*(double n, const Time &t) {
    Time mul;
    long totalMinutes = (t.hours * 60 + t.minutes) * n;
    mul.minutes = totalMinutes % 60;
    mul.hours = totalMinutes / 60;
    return mul;
}

Time operator*(const Time &t, double n) {
    return operator*(n, t);
}