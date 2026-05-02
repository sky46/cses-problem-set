#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    int n;
    int a;
    int b;
    for (int i{0}; i < t; ++i) {
        std::cin >> n >> a >> b;
        std::vector<int> a_moves;
        std::vector<int> b_moves;
        std::vector<int> both_moves;
        int sum{a + b};
        if (sum > n || !((a > 0 && b > 0) || (a == 0 && b == 0))) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
            for (int j{sum + 1}; j <= n; ++j) {
                both_moves.push_back(j);
            }
            // a wins
            for (int j{1}; j <= a; ++j) {
                a_moves.push_back(b + j);
                b_moves.push_back(j);
            }
            // b wins
            for (int j{1}; j <= b; ++j) {
                a_moves.push_back(j);
                b_moves.push_back(a + j);
            }

            for (int& move : both_moves) {
                std::cout << move << ' ';
            }
            for (int& move : a_moves) {
                std::cout << move << ' ';
            }
            std::cout << std::endl;

            for (int& move : both_moves) {
                std::cout << move << ' ';
            }
            for (int& move : b_moves) {
                std::cout << move << ' ';
            }
            std::cout << std::endl;
        }
    }
}