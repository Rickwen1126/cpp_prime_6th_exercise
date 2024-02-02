#include <list>
#include <string>
#include <set>
#include <iterator>
#include <iostream>


int main() {
    using namespace std;
    list<string> matList{"Jack", "Tracy", "Mark", "Fat", "Fuck"};
    list<string> patList{"Jack", "Scott", "Derek", "Rick", "Fat"};
    set<string> resultSet;
    ostream_iterator<string, char> out(cout, " ");

    matList.push_back("Pat");
    patList.push_back("Mat");
    matList.merge(patList);
    matList.unique();

    copy(matList.begin(), matList.end(), out);

    return 0;
}