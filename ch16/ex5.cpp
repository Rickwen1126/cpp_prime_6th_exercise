#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>

template<class T>
int reduce(T ar[], int n) {
    std::sort(&ar[0], &ar[n]);
    auto endIter = std::unique(&ar[0], &ar[n]);

    int len = 0;

    for (auto iter = &ar[0] ; iter != endIter; iter++) {
        len++;
    }

    return len;
}

int main() {
    // long ar[8] = {9, 9 ,8, 9, 6, 7, 6, 2};

    std::string ar[8] = {"a", "x" ,"x", "a", "hh", "hh", "b", "x"};
    int len = reduce(ar, 8);
    std::ostream_iterator<std::string, char> out_iter(std::cout, " ");

    std::copy(&ar[0], &ar[len], out_iter);

    return 0;

}
