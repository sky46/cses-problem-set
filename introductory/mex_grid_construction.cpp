#include <iostream>
#include <vector>
#include <set>

int main() {
    short n;
    std::cin >> n;
    std::vector<std::set<short>> rows(100);
    std::vector<std::set<short>> cols(100);
    for (short r{0}; r < n; ++r) {
        for (short c{0}; c < n; ++c) {
            int x{0};
            while (rows[r].find(x) != rows[r].end() || cols[c].find(x) != cols[c].end()) {
                ++x;
            }
            std::cout << x << ' ';
            rows[r].insert(x);
            cols[c].insert(x);
        }
        std::cout << std::endl;
    }
}