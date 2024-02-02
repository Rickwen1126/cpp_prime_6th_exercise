#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>
#include <iterator>

std::vector<int> Lotto(int maxSpot, int nums) {
    std::vector<int> spots;
    std::vector<int> result;
    
    for (int i = 1; i <= maxSpot; i++) {
        spots.push_back(i);
    }

    std::random_shuffle(spots.begin(), spots.end());

    srand(time(nullptr));
    int startIdx = rand() % (maxSpot - nums);

    for (int i = 0; i < nums; i++) {
        result.push_back(spots[startIdx + i]);
    }

    return result;
}


int main() {
    std::ostream_iterator<int, char> prt_iter(std::cout, " ");
    auto ar = Lotto(52, 6);
    std::copy(ar.begin(), ar.end(), prt_iter);

    return 0;
}
