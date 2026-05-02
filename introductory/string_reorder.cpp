#include <iostream>
#include <string>

// Number of each letter A-Z left to place
int counts[26]{};

// When we have n chars left we can place at most max_count = ceil(n/2) of the same char, e.g. ABACA.
// So at each step, look through remaining counts. If any over max_count, print -1 and exit because failed.
// If any equal to max_count, take first of these and place.
// Otherwise, take first and place to build lexographically minimal string.

int main() {
    std::string str;
    std::cin >> str;
    for (char& c : str) {
        ++counts[c - 65];
    }
    std::string res;
    int len{static_cast<int>(str.size())};
    for (int i{0}; i < len; ++i) {
        int max_count{(len - i + 1) / 2}; // Ceiling division of chars left / 2
        bool found{false};
        for (int j{0}; j < 26; ++j) {
            if (counts[j] > max_count) {
                std::cout << "-1\n";
                return 0;
            } else if (counts[j] == max_count && (len - i) % 2 == 1) {
                // This is the last chance to place this one
                if (found || (i > 0 && res[i - 1] == j + 65)) { // Found or prev is same  
                    std::cout << "-1\n";
                    return 0;
                } else {
                    found = true;
                    res.push_back(j + 65);
                    --counts[j];
                }
            }
        }
        if (!found) {
            for (int j{0}; j < 26; ++j) {
                if (counts[j] > 0 && !(i > 0 && res[i - 1] == j + 65)) {
                    res.push_back(j + 65);
                    --counts[j];
                    break;
                }
            }
        }
    }
    std::cout << res << '\n';
}