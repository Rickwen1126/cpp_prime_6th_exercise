#ifndef WINE_H_
#define WINE_H_
#include <string>
#include <valarray>
#include <iostream>
#include <cstring>

using ArrayInt = std::valarray<int>;
using PairArray = std::pair<ArrayInt, ArrayInt>;
class Wine {
    private:
        std::string name;
        PairArray vintages;
        int years;
    public:
        Wine(const char *l, int y, const int yr[], const int bot[]) : name(l), years(y), vintages(ArrayInt(yr, y), ArrayInt(bot, y)){}
        Wine(const char *l, int y) : name(l), years(y), vintages(ArrayInt(y), ArrayInt(y)) {}
        std::string Label() const {
            return name;
        }
        int sum() const {
            return vintages.second.sum();
        }
        void GetBottles() {
            using std::cout;
            using std::cin;
            using std::endl;
            cout << "Enter " << name << " data for " << years << " year(s):" << endl;
            for (int i = 0; i < years; i++) {
                int year;
                int count;
                cout << "Enter year:";
                cin >> year;
                cout << "Enter bottles for that year:";
                cin >> count;
                vintages.first[i] = year;
                vintages.second[i] = count;
            }
        }

        void Show() const{
            using std::cout;
            using std::cin;
            using std::endl;
        
            cout << "Wine: " << name << endl;
            std::printf("%12s %10s\n", "Year", "Bottles");
            for (int i = 0 ; i < years; i++){
                std::printf("%8s%-6d  %d\n", "",vintages.first[i], vintages.second[i]);
            }
        }
};

#endif 