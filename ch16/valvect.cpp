#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;
    vector<double> data;
    double temp;

    cout << "Enter numbers (<= 0 to quit):\n";
    while(cin >> temp && temp > 0)
        data.push_back(temp);
    
    sort(data.begin(), data.end());
    int size = data.size();
    valarray<double> numbers(size);
    int i;
    for (i = 0; i < size; i++) {
        numbers[i] = data[i];
    }

    return 0;
}