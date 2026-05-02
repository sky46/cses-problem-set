#include <iostream>
#include <vector>

std::vector<std::vector<bool>> codes(1 << 17);

int main() {
    codes[0].push_back(0);
    codes[1].push_back(1);
    int n;
    std::cin >> n;
    int end_i{2}; // same as next start_i
    int start_i{0};
    int prev_start_i;
    for (int i{2}; i <= n; ++i) {
        prev_start_i = start_i;
        start_i = end_i;
        end_i = (1 << (i + 1)) - 2;
        for (int j{0}; j < start_i - prev_start_i; ++j) {
            std::vector<bool>& new_entry1{codes[start_i + j]};
            std::vector<bool>& new_entry2{codes[end_i - 1 - j]};
            std::vector<bool>& old_entry{codes[prev_start_i + j]};
            new_entry1.push_back(0);
            new_entry1.insert(new_entry1.end(), old_entry.begin(), old_entry.end());
            new_entry2.push_back(1);
            new_entry2.insert(new_entry2.end(), old_entry.begin(), old_entry.end());
        }
    }
    int code_end{(1 << (n + 1)) - 2};
    for (int i{(1 << n) - 2}; i < code_end; ++i) {
        for (auto b : codes[i]) {
            std::cout << b;
        }
        std::cout << std::endl;
    }
    return 0;
}
