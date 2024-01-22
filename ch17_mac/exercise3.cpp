#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    using namespace std;
    if (argc <= 2) {
        cerr << "You must offer two filenames to do copy";
        return 1;
    }

    char *srcName = argv[1];
    char *dstName = argv[2];
    ifstream fin;
    ofstream fout;
    fin.open(srcName);
    fout.open(dstName);

    if (fin.is_open() == false) {
        cerr << "Src file is wrong: " << srcName;
        return 1;
    }

    if (fout.is_open() == false) {
        cerr << "Dst file is wrong: " << dstName;
    }

    char ch;
    while ((ch = fin.get()) != EOF && fout.good()) {
        fout.put(ch); 
    }

    fin.close();
    fout.close();

    return 0;
}