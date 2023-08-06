#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

char toLower(char ch) {return tolower(ch);}
string & ToLower(string &st);
void display(const string &s);

int main() {
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while(cin >> input && input !="quit") {
        words.push_back(input);
    }

    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;
    set<string> wordSet;
    transform(words.begin(), words.end(), insert_iterator<set<string>>(wordSet, wordSet.begin()), ToLower);
    cout << "Alphabetic list of words:\n";
    for_each(wordSet.begin(), wordSet.end(), display);
    cout << endl;

    map<string, int> wordmap;
    set<string>::iterator si;
    for (si = wordSet.begin(); si != wordSet.end(); si++) {
        wordmap[*si] = count(words.begin(), words.end(), *si);
    }

    cout << "\nWord frequency:\n";

    for (auto iter = wordmap.begin(); iter != wordmap.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }

    return 0;
}

string &ToLower(string &st) {
    transform(st.begin(), st.end(), st.begin(), toLower);

    return st;
}

void display(const string &s) {
    cout << s << " ";
}