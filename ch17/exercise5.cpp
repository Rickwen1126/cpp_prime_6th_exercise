#include <list>
#include <iostream>
#include <fstream>
#include <string>

#define MAT_FRIENDS_FILE "mat.dat"
#define PAT_FRIENDS_FILE "pat.dat"
#define MERGER_FILE "matnpat.dat"

int main() {
    using namespace std;
    ifstream fin;
    list<string> patList;
    list<string> matList;

    fin.open(MAT_FRIENDS_FILE);

    if (fin.is_open() == false) {
        cerr << "open " << MAT_FRIENDS_FILE << " error";
        return 1;
    }

    string name;

    while (getline(fin, name))
    {
        matList.push_back(name);
    }
    
    matList.sort();

    cout << "Mat's Friends:" << endl;
    for (string n : matList) {
        cout << n << endl;
    }

    fin.close();
    fin.clear();
    fin.open(PAT_FRIENDS_FILE);

    if (fin.is_open() == false) {
        cerr << "open " << MAT_FRIENDS_FILE << " error";
        return 1;
    }

    while(getline(fin, name)) {
        patList.push_back(name);
    }

    patList.sort();

    cout << endl;
    cout << "Pat's Friends:" << endl;
    for (string n : patList) {
        cout << n << endl;
    }

    matList.merge(patList);
    matList.unique();

    ofstream fout(MERGER_FILE);
    
    if (false == fout.is_open()) {
        cerr << "Open file:" << MERGER_FILE << " failed";
        return 1;
    }

    for (string s : matList) {
        fout << s << endl;
    }

    fin.close();
    fout.close();

    return 0; 
}