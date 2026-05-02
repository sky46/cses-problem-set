#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> indexes(n + 1); // indexes[v] is index of value v. Note values are [1, n+1)
    int v;
    for (int i = 1; i <= n; ++i) {
        std::cin >> v;
        indexes[v] = i;
    }
    int rounds = 1;
    int cur_sweep_index = -1;
    for (int i = 1; i <= n; ++i) {
        if (indexes[i] < cur_sweep_index) {
            ++rounds;
        }
        cur_sweep_index = indexes[i];
    }
    std::cout << rounds << '\n';
}