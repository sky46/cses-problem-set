#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

// If at bounds the out-of-bound one doesn't add any. 
int get_x_idx(int y_val, std::vector<int>* indexes_p) {
    if (y_val == 1) {
        return -1;
    } else {
        return (*indexes_p)[y_val - 1];
    }
}

// If at bounds the out-of-bound one doesn't add any. 
int get_z_idx(int y_val, std::vector<int>* indexes_p, int n) {
    if (y_val == n) {
        return n + 1;
    } else {
        return (*indexes_p)[y_val + 1]; // will not overflow
    }
}
// rounds added (0-2) from x->y and y->z. x,y,z are indexes at three adjacent values.
int rounds_added(int y_val, std::vector<int>* indexes_p, int n, bool exclude_xy, bool exclude_yz) {
    int r = 0;
    int x_idx = get_x_idx(y_val, indexes_p);
    int y_idx = (*indexes_p)[y_val];
    int z_idx = get_z_idx(y_val, indexes_p, n);
    if (y_idx < x_idx && !exclude_xy) {
        ++r;
    }
    if (z_idx < y_idx && !exclude_yz) {
        ++r;
    }
    return r;
}


int main() {
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<int> indexes(n + 1); // indexes[v] is index of value v. Note values are [1, n+1)
    std::vector<int> values(n + 1);
    int v;
    for (int i = 1; i <= n; ++i) {
        std::cin >> v;
        indexes[v] = i;
        values[i] = v;
    }
    int rounds = 1;
    int cur_sweep_index = -1;
    for (int i = 1; i <= n; ++i) {
        if (indexes[i] < cur_sweep_index) {
            ++rounds;
        }
        cur_sweep_index = indexes[i];
    }

    int a_idx;
    int b_idx;
    int a_val;
    int b_val;
    for (int i = 0; i < m; ++i) {
        std::cin >> a_idx >> b_idx;
        a_val = values[a_idx];
        b_val = values[b_idx];
        
        // calculate rounds previously added from a-1 a a+1, then calculate rounds now added, apply difference to total. same for b
        
        // skip overlap for b only so it only gets counted once. here x,y,z are about y=b.
        bool overlap_xy_b = b_val == a_val + 1; // x=a, y=b
        bool overlap_yz_b = b_val == a_val - 1; // y=b, z=a

        int rounds_added_before_a = rounds_added(a_val, &indexes, n, false, false);
        int rounds_added_before_b = rounds_added(b_val, &indexes, n, overlap_xy_b, overlap_yz_b);

        std::swap(indexes[a_val], indexes[b_val]);
        std::swap(values[a_idx], values[b_idx]);

        int rounds_added_after_a = rounds_added(a_val, &indexes, n, false, false);
        int rounds_added_after_b = rounds_added(b_val, &indexes, n, overlap_xy_b, overlap_yz_b);

        rounds += rounds_added_after_a - rounds_added_before_a;
        rounds += rounds_added_after_b - rounds_added_before_b;
        
        std::cout << rounds << '\n';
    }
}