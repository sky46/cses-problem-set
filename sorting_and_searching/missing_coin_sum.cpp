#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }
    std::sort(coins.begin(), coins.end());
    long long max_can_create = 0;
    for (const auto& c : coins) {
        // with c we can create all from c + 1 to c + max_can_create, inclusive
        if (c > max_can_create + 1) { // then we have no way of creating max_can_create + 1 since min created with c is c + 1
            break;
        } else {
            max_can_create += c;
        }
    }
    std::cout << max_can_create + 1;
}