#include <iostream>
#include <string>
#include <algorithm>


class isParlindrome {
    public:
        virtual bool operator()(const std::string &s) {
            int left = 0;
            int right = s.size() - 1;
            while(left <= right) {
                if (s[left++] != s[right--]) {
                    return false;
                }
            }
            return true;
        }
};

class isParlindromeV2 : public isParlindrome{
    private:
        void tolowercase(std::string &s) {
            std::transform(s.begin(), s.end(), s.begin(), tolower);
        }

        void removeExtraChar(std::string &s) {
            int slow = 0;
            int fast = 0;
            while (fast != s.size()) {
                if (s[fast] >= 'a' && s[fast] <= 'z') {
                    s[slow++] = s[fast++];
                } else {
                    fast++;
                }
            }

            s.resize(slow);
        }
    public:
        virtual bool operator()(const std::string &s) {
            std::string tmpS(s);
            tolowercase(tmpS);
            std::cout << tmpS << std::endl;
            removeExtraChar(tmpS);

            std::cout << tmpS << std::endl;

            return isParlindrome::operator()(tmpS);
        }
};


int main() {
    using namespace std;
    string s;
    string version;
    cout << "Please enter version (v1, v2) to select the palindrome check algorithm:";
    cin >> version;
    cin.get();
    isParlindrome *isP = new isParlindrome; 
    if (version == "v2") {
        delete isP;
        isP = new isParlindromeV2;
    } 
    cout << "Please enter a string to check if it is palindrome (or enter q to leave): "; 
    while(getline(cin, s) && s != "q") {
        if ((*isP)(s)) {
            cout << "is palindrome" << endl;
        } else {
            cout << "is not palindrome" << endl;
        }

        cout << "Please enter a string to check if it is palindrome (or enter q to leave): ";
    }

    return 0;
}