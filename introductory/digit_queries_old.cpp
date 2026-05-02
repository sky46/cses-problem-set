#include <iostream>

// 0-indexed
short dig_from_right(short dig, long long n) {
    for (short i{0}; i < dig; ++i) {
        n /= 10;
    }
    return static_cast<short>(n % 10);
}

void print_dig(long long k) {
    long long n_to_add{1};
    int n_dig{1};
    long long mag_10{10};
    while (true) {
        if (n_to_add == mag_10) {
            mag_10 *= 10;
            ++n_dig;
        }
        if (k <= n_dig) {
            std::cout << dig_from_right(n_dig - k, n_to_add) << std::endl;
            return;
        } 
        ++n_to_add;
        k -= n_dig;
    }
}

int main() {
    int q;
    long long k;
    std::cin >> q;
    for (int i{0}; i < q; ++i) {
        std::cin >> k;
        print_dig(k);
    }
}
