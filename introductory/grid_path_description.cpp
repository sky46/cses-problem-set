#include <iostream>
#include <string>

std::string descr;
bool vis[7][7]{};
int moves[4][2]{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};
char moves_letters[4]{'R','D','L','U'};
// x,y zero-indexed, starting from top left
int x{0};
int y{0};
int moves_made{0};
int paths{0};
int prev_move{1}; // down for first, could be right too

bool valid(int x, int y) {
    return 0 <= x && x < 7 && 0 <= y && y < 7 && !vis[x][y];
}

// If an adjacent square is surrounded on three sides (including us) it will be a dead end unless we move to it
bool will_be_dead_end(int x, int y) {
    int blocked_sides{0};
    for (int move{0}; move < 4; ++move) {
        if (!valid(x + moves[move][0], y + moves[move][1])) {
            ++blocked_sides;
        }
    }
    return blocked_sides == 3;
}

// If it can't go in the same direction as before and can turn either way, it will split
// the remaining squares in two separate regions making one impossible to reach.
bool must_split() {
    // Loop adj moves back around if outside of 0-3
    int adj_move_1{(prev_move + 3) % 4};
    int adj_move_2{(prev_move + 1) % 4};
    return (
        !valid(x + moves[prev_move][0], y + moves[prev_move][1]) &&
        valid(x + moves[adj_move_1][0], y + moves[adj_move_1][1]) &&
        valid(x + moves[adj_move_2][0], y + moves[adj_move_2][1])
    );
}

void search() {
    if (x == 0 && y == 6) {
        if (moves_made == 48) {
            ++paths;
        }
        return;
    }
    if (must_split()) {
        return;
    }
    
    for (int move{0}; move < 4; ++move) {
        if (!(descr[moves_made] == '?' || descr[moves_made] == moves_letters[move])) {
            continue;
        }
        x += moves[move][0];
        y += moves[move][1];
        if (valid(x, y)) {
            ++moves_made;
            vis[x][y] = true;
            int prev_prev_move{prev_move};
            prev_move = move;
            search();
            --moves_made;
            vis[x][y] = false;
            prev_move = prev_prev_move;
            // fine to create dead end in last square
            if (will_be_dead_end(x, y) && !(x == 0 && y == 6)) {
                x -= moves[move][0];
                y -= moves[move][1];
                break;
            }
        }
        x -= moves[move][0];
        y -= moves[move][1];
    }
}

int main() {
    std::cin >> descr;
    vis[0][0] = true;
    search();
    std::cout << paths << '\n';
}