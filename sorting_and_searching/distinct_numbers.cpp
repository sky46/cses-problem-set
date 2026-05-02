#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> list;
    int n;
    std::cin >> n;
    list.resize(n);
    for (int i{0}; i < n; ++i) {
        std::cin >> list[i];
    }
    std::sort(list.begin(), list.end());
    int distinct_count{1};
    for (int i{1}; i < n; ++i) {
        if (list[i] != list[i-1]) {
            ++distinct_count;
        }
    }
    std::cout << distinct_count << '\n';
}