#include <iostream>

// 0-indexed
short dig_from_right(long long n, short dig) {
    for (short i{0}; i < dig; ++i) {
        n /= 10;
    }
    return static_cast<short>(n % 10);
}

void print_dig(long long remaining) {
    int dig_count{1};
    long long dc_to_remove_numbers{9}; // How many numbers for this dig_count
    long long next_n{1};
    long long to_remove_digits{dig_count * dc_to_remove_numbers}; // How many digits for this dig_count
    while (to_remove_digits < remaining) {
        remaining -= to_remove_digits;
        next_n += dc_to_remove_numbers;
        ++dig_count;
        dc_to_remove_numbers *= 10;
        to_remove_digits = dig_count * dc_to_remove_numbers;
    }
    if (remaining % dig_count != 0) {
        dc_to_remove_numbers = remaining / dig_count;
    } else {
        dc_to_remove_numbers = (remaining - 1) / dig_count;
    }
    to_remove_digits = dc_to_remove_numbers * dig_count;
    remaining -= to_remove_digits;
    next_n += dc_to_remove_numbers;
    std::cout << dig_from_right(next_n, dig_count - remaining) << std::endl;
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
