#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");
    if (fin.is_open() == false) {
        cerr << "Can't open file. Buy" << endl;
        exit(EXIT_FAILURE);
    }

    string item;
    int count = 0;
    getline(fin, item, ':');
    while(fin.good()) {
        count++;
        cout << count << ": " << item <<endl;
        getline(fin, item, ':');
    }

    cout << "Done\n";
    fin.close();
    
    return 0;
}