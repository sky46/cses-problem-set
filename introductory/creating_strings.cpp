#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>


std::map<char, int> avail;
std::set<std::string> results;

void add_chars(int count, std::string cur) {
    if (count == 1) {
        for (auto [c, n] : avail) {
            if (n != 0) {
                results.insert(cur + c);
                return;
            }
        }
    } else {
        for (auto [c, n] : avail) {
            if (n != 0) {
                --avail[c];
                add_chars(count - 1, cur + c);
                ++avail[c];
            }
        }
    }
}

int main() {
    std::string str;
    std::cin >> str;
    for (char& c : str) {
        ++avail[c];
    }
    add_chars(str.size(), "");
    std::cout << results.size() << std::endl;
    for (auto result : results) {
        std::cout << result << std::endl;
    }
}