#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<char> options{'A', 'B', 'C', 'D'};
    int n;
    int m;
    std::cin >> n >> m;
    std::string prev_row;
    std::string cur_row;
    std::string new_row;
    for (int r{0}; r < n; ++r) {
        std::cin >> cur_row;
        for (int c{0}; c < m; ++c) {
            std::unordered_set<char> new_options{options};
            new_options.erase(cur_row[c]);
            if (c >= 1) {
                new_options.erase(new_row[c - 1]);
            }
            if (r >= 1) {
                new_options.erase(prev_row[c]);
            }
            new_row.push_back(*new_options.begin());
        }
        std::cout << new_row << std::endl;
        prev_row = new_row;
        new_row.clear();
    }
}