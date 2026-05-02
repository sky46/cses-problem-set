#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    long long max = a[0];
    long long cur_sum = 0;
    for (const auto& x : a) {
        if (cur_sum < 0) {
            cur_sum = x;
        } else {
            cur_sum += x;
        }
        if (cur_sum > max) {
            max = cur_sum;
        }
    }
    std::cout << max << '\n';
}