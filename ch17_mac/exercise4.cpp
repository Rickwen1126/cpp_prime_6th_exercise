#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    using namespace std;
    if (argc <= 3) {
        cerr << "Please enter 3 files name to merge it.";
        return 1;
    }

    ifstream fin1;
    ifstream fin2;
    ofstream fout;
    fin1.open(argv[1]);
    fin2.open(argv[2]);
    fout.open(argv[3]);

    if (fin1.is_open() == false) {
        cerr << "File: " << argv[1] << " is wrong";
        return 1;
    }

    if (fin2.is_open() == false)
    {
        cerr << "File: " << argv[2] << " is wrong";
        return 1;
    }

    if (fout.is_open() == false)
    {
        cerr << "File: " << argv[3] << " is wrong";
        return 1;
    }

    while (!fin1.eof() || !fin2.eof()) {
        string curLine;
        if (fin1.good()) {
            string tmp;
            getline(fin1, tmp);
            curLine += tmp;
        }

        if (fin2.good()) {
            string tmp;
            getline(fin2, tmp);
            curLine += " " + tmp;
        }
        
        cout << "write line: " << curLine; 
        
        fout << curLine << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}