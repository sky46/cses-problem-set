#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    int max;
    std::cin >> n >> max;
    std::vector<int> weights(n);
    for (int& w : weights) {
        std::cin >> w;
    }
    std::sort(weights.begin(), weights.end());
    auto l{weights.begin()};
    auto r{weights.end() - 1};
    int count{0};
    while (l < r) {
        if (*l + *r <= max) {
            ++l;
        }
        ++count;
        --r;
    }
    if (l == r) {
        ++count;
    }
    std::cout << count << '\n';
}