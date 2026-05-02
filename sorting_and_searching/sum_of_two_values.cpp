#include <iostream>
#include <vector>
#include <map>

int main() {
    int n;
    int sum;
    std::cin >> n >> sum;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }
    std::map<int, int> m; // value, pos
    for (int i = 0; i < n; ++i) {
        int other_val = sum - a[i];
        auto other = m.find(other_val);
        if (other != m.end()) {
            std::cout << other->second + 1 << ' ' << i + 1 << '\n'; //1-indexed
            return 0;
        } else {
            m[a[i]] = i;
        }
    }
    std::cout << "IMPOSSIBLE" << '\n';
}