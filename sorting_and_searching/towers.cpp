#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::multiset<int> tower_tops;
    for (int i = 0; i < n; ++i) {
        int add_cube;
        std::cin >> add_cube;
        auto add_to_tower = tower_tops.upper_bound(add_cube);
        if (add_to_tower != tower_tops.end()) {
            tower_tops.erase(add_to_tower);
        }
        tower_tops.insert(add_cube);
    }
    std::cout << tower_tops.size() << '\n';
}