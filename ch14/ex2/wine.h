#ifndef WINE_H_
#define WINE_H_
#include <string>
#include <valarray>
#include <iostream>
#include <cstring>

using ArrayInt = std::valarray<int>;
using PairArray = std::pair<ArrayInt, ArrayInt>;
class Wine : private std::string, private PairArray{
    private:
        int years;
    public:
        Wine(const char *l, int y, const int yr[], const int bot[]) : std::string(l), years(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)){}
        Wine(const char *l, int y) : std::string(l), years(y), PairArray(ArrayInt(y), ArrayInt(y)) {}
        std::string Label() const {
            return (std::string)*this;
        }
        int sum() const {
            return ((const PairArray)*this).second.sum();
        }
        void GetBottles() {
            using std::cout;
            using std::cin;
            using std::endl;
            cout << "Enter " << (std::string) * this << " data for " << years << " year(s):" << endl;
            for (int i = 0; i < years; i++) {
                int year;
                int count;
                cout << "Enter year:";
                cin >> year;
                cout << "Enter bottles for that year:";
                cin >> count;
                ((PairArray*)this)->first[i] = year;
                ((PairArray*)this)->second[i] = count;
            }
        }

        void Show() const{
            using std::cout;
            using std::cin;
            using std::endl;

            cout << "Wine: " << (std::string)*this << endl;
            std::printf("%12s %10s\n", "Year", "Bottles");
            for (int i = 0 ; i < years; i++){
                std::printf("%8s%-6d  %d\n", "", ((PairArray) * this).first[i], ((PairArray) * this).second[i]);
            }
        }
};

#endif 