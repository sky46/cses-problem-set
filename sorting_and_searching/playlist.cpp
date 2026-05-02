#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    int s;
    std::map<int, int> last_idxs;
    int longest = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        std::cin >> s;
        auto last_idx = last_idxs.find(s);
        if (last_idx != last_idxs.end() && last_idx->second >= l) {
            l = last_idx->second + 1;
        } else if (r - l + 1 > longest) {
            longest = r - l + 1;
        }
        last_idxs[s] = r;
    }
    std::cout << longest << '\n';
}