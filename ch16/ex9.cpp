#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <iostream>

const int BIG_NUM = 4000000;

int main() {
    using namespace std;
    srand(time(nullptr));
    vector<int> vi0(BIG_NUM);
    for (int i = 0; i < BIG_NUM; i++) {
        vi0[i] = rand() % BIG_NUM;
    }

    vector<int> vi(vi0.begin(), vi0.end());
    list<int> li(vi0.begin(), vi0.end());
    list<int> li2(vi0.begin(), vi0.end());

    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();

    cout << "Sort time for vector:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
    
    start = clock();
    li.sort();
    end = clock();

    cout << "Sort time for list:" << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    vector<int> vi2(li2.begin(), li2.end());
    sort(vi2.begin(), vi2.end());
    copy(vi2.begin(), vi2.end(), li2.begin());
    end = clock();

    cout << "Sort time for list cp to vector then cp back:" << (double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}