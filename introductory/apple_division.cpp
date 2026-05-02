#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<int> weights;

long long min_diff(int index, long long sum1, long long sum2) {
    if (weights.size() - index == 1) {
        return std::abs(std::abs(sum1 - sum2) - weights[index]);
    } else {
        return std::min(
            min_diff(index + 1, sum1 + weights[index], sum2),
            min_diff(index + 1, sum1, sum2 + weights[index])
        );
    }
}

int main() {
    int n;
    std::cin >> n;
    weights.resize(n);
    for (int i{0}; i < n; ++i) {
        std::cin >> weights[i];
    }
    std::cout << min_diff(0, 0, 0) << std::endl;
}