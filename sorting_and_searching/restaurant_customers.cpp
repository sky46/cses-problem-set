#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arrive(n);
    std::vector<int> leave(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arrive[i] >> leave[i];
    }
    std::sort(arrive.begin(), arrive.end());
    std::sort(leave.begin(), leave.end());
    int max = 0;
    int current = 0;
    // a,l are next arriving,leaving
    auto a = arrive.begin();
    auto l = leave.begin();
    while (a != arrive.end()) { // we will always finish arriving before or at same time as leaving and after that max can't increase
        if (*a == *l) {
            ++a;
            ++l;
            // net 0
        } else if (*a < *l) {
            // next arriving is before next leaving
            ++current;
            if (current > max) {
                max = current;
            }
            ++a;
        } else {
            //next leaving is before next arriving
            --current;
            ++l;
        }
    }
    std::cout << max << '\n';
}