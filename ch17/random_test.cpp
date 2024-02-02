#include <iostream>
#include <fstream>

#include <iomanip>
#include <cstdlib>
#include <vector>

static const char* fileName = "planet.dat";


struct Planet {
    char name[20];
    double population;
    double g;
};

void printWellcomeEnterInfo() {
    using namespace std;
    cout << "Please enter num to select data you want to modify (any alphabet to exit):";
}

void showPlList(const std::vector<Planet> &list) {
    using namespace std;
    for (int i = 0 ; i < list.size(); i++) {
        cout << "Record " << i + 1 << ": " << list[i].name << " " << list[i].population << " " << list[i].g << endl;        
    }
}


int main() {
    using namespace std;
    fstream finout(fileName, ios::in | ios::out | ios::binary);
    // ofstream fout(fileName, ios::out | ios::binary);

    Planet pl;
    vector<Planet> plList;

    if (finout.is_open()) {
        while(finout.read((char*)&pl, sizeof pl)){
            plList.push_back(pl);
        }

        if (finout.eof()) finout.clear();
    } else {
        cerr << "Open file:" << fileName << " failed!";
        exit(EXIT_FAILURE); 
    }

    cout << "The file content:" << endl;
    showPlList(plList);

    printWellcomeEnterInfo();
    int num = 0;

    while (cin >> num) {
        if (num <= 0  || num > plList.size()) {
            cout << "Please enter num range between " << 1 << " to " << plList.size() << endl;
            printWellcomeEnterInfo();
            continue;
        }
        
        cout << "Please enter modify name:";
        cin >> plList[num - 1].name;
        cout << "Please enter modify population:";
        cin >> plList[num - 1].population;
        cout << "Please enter modify g:";
        cin >> plList[num - 1].g;

        pl = plList[num - 1];

        streampos pos = ((long)(num - 1)) * (sizeof pl);
        cout << "POS:" << pos;
        finout.seekp(pos);
        finout.write((char*)&pl, sizeof pl) << flush;

        cout << "The file content:" << endl;
        showPlList(plList);

        printWellcomeEnterInfo();
    }

    finout.close();
        
    return 0;
}
