#include <iostream>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x;
    int n;
    std::cin >> x >> n;
    std::set<int> lights{0, x}; // 'fake lights' at start and end
    std::multiset<int> dists;
    dists.insert(x);
    for (int i = 0; i < n; ++i) {
        int p;
        std::cin >> p;
        auto right = lights.upper_bound(p);
        auto left = right;
        --left; // there can't already be light at p so left is guaranteed to be directly before right
        int splitting_dist = *right - *left;
        int new_dist_right = *right - p;
        int new_dist_left = p - *left;
        dists.erase(dists.find(splitting_dist));
        dists.insert(new_dist_left);
        dists.insert(new_dist_right);
        lights.insert(p);
        auto last = dists.end();
        --last;
        std::cout << *last << '\n';
    }
}