#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> sticks(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sticks[i];
    }
    std::sort(sticks.begin(), sticks.end());
    int mid = sticks[n/2];
    long long dist = 0;
    for (const auto& s : sticks) {
        dist += std::abs(mid - s);
    }
    std::cout << dist << '\n';
}