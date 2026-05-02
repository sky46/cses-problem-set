#include <iostream>
#include <queue>
#include <utility>

short grid[1000][1000]{0};
short moves[8][2]{
    {1, 2},
    {1, -2},
    {-1, -2},
    {-1, 2},
    {2, 1},
    {2, -1},
    {-2, -1},
    {-2, 1},
};
short n;

int main() {
    std::cin >> n;
    std::queue<std::pair<short, short>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        short r{q.front().first};
        short c{q.front().second};
        q.pop();
        for (auto move : moves) {
            short new_r{static_cast<short>(r + move[0])};
            short new_c{static_cast<short>(c + move[1])};
            if (0 <= new_r && new_r < n &&
                0 <= new_c && new_c < n &&
                grid[new_r][new_c] == 0 &&
                !(new_r == 0 && new_c == 0)
            ) {
                grid[new_r][new_c] = grid[r][c] + 1;
                q.emplace(new_r, new_c);
        }
    }
    }
    for (short r{0}; r < n; ++r) {
        for (short c{0}; c < n; ++c) {
            std::cout << grid[r][c] << ' ';
        }
        std::cout << std::endl;
    }
}