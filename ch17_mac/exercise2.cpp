#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    using namespace std;
    if (argc <= 1) {
        cerr << "Please enter filename";
        return 1; 
    }
    char *fileName = argv[1];

    ofstream fout;

    fout.open(fileName);

    if (fout.is_open() == false) {
        cerr << "open file failed with filename: " << fileName;
        return 1;
    }

    cout << "Please enter content to save to file: " << fileName << endl;

    char ch;
    while ((ch = cin.get()) != EOF) {
        fout << ch;
    }

    fout.close();

    return 0;
}