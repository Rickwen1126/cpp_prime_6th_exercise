#include <list>
#include <algorithm>
#include <iterator>
#include <iostream> 

using std::list;
int reduce(long ar[], int n)
{
    std::sort(&ar[0], &ar[n]);
    auto endIter = std::unique(&ar[0], &ar[n]);

    int resultLen = 0;

    for (auto iter = &ar[0]; iter != endIter; iter++) {
        resultLen++;
    }

    return resultLen;
}


int main() {
    long ar[8] = {9, 9 ,8, 9, 6, 7, 6, 2};
    int len = reduce(ar, 8);
    std::ostream_iterator<long, char> out_iter(std::cout, " ");

    std::copy(&ar[0], &ar[len], out_iter);

    return 0;
}