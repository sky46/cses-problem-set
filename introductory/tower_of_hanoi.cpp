#include <iostream>
#include <utility>
#include <vector>


// To move n disks from A to C:
// Move top n - 1 disks to B
// Move bottom disk to C
// Move remaning n - 1 disks to C
std::vector<std::pair<char, char>> moves;

void move_disks(int count, char from, char to, char other) {
    if (count == 1) {
        moves.push_back(std::make_pair(from, to));
    } else {
        move_disks(count - 1, from, other, to);
        move_disks(1, from, to, other); 
        move_disks(count - 1, other, to, from);
    }
}

int main() {
    int n;
    std::cin >> n;
    move_disks(n, '1', '3', '2');
    std::cout << moves.size() << std::endl;
    for (auto [from, to] : moves) {
        std::cout << from << ' ' << to << std::endl;
    }
}