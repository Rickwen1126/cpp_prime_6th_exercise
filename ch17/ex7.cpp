#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

void ShowStr(const std::string &s) {
    std::cout << s << std::endl;
}

void GetStrs(std::ifstream &fin, std::vector<std::string> &arr){
    char sizeVal[100] = {'\0'};
    while (fin.read(sizeVal, sizeof(size_t))) {
        size_t len = (size_t)*sizeVal;
        char c;
        std::string s;
        while (len > 0) {
            fin.read(&c, 1);
            s += c;
            len--;
        }
        arr.push_back(s);
    }
}

class Store {
    private:
        std::ofstream &fout;
    public:
        Store(std::ofstream &fout) : fout(fout) {}
        void operator()(const std::string &s) {
            size_t len = s.size();
            fout.write((char*)&len, sizeof(size_t));
            fout.write(s.data(), len);
        }
};

int main() {
    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr << "Could not openpen file for input. \n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    cout << "\nHere are the stings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

    