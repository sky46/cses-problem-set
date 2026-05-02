#include <iostream>
#include <string>

bool reserved[8][8];
bool cols[8]{0};
bool diags1[15]{0};
bool diags2[15]{0};
int ways{0};

void place_queen(int r) {
    for (int c{0}; c < 8; ++c) {
        if (!reserved[r][c] && !cols[c] && !diags1[r + c] && !diags2[8 - r + c]) {
            if (r == 7) {
                ++ways;
                return;
            } else {
                cols[c] = 1;
                diags1[r + c] = 1;
                diags2[8 - r + c] = 1;
                place_queen(r + 1);
                cols[c] = 0;
                diags1[r + c] = 0;
                diags2[8 - r + c] = 0;
            }
        }
    }
}

int main() {
    std::string line;
    for (int r{0}; r < 8; ++r) {
        std::cin >> line;
        for (int c{0}; c < 8; ++c) {
            reserved[r][c] = line[c] == '*';
        }
    }
    place_queen(0);
    std::cout << ways << std::endl;
}