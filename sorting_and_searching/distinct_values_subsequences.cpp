#include <iostream>
#include <map>

int main() {
	int n;
	std::cin >> n;
	std::map<int, int> counts;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		++counts[x];
	}
	long long res = 1;
	long long mod_mask = 1'000'000'000 + 7;
	for (auto val_count : counts) {
		// Find all combinations of including each value 0 or 1 times.
		// There are [count] ways of including [val] 1 time (1 for each occurrence), then +1 for including 0.
		res *= val_count.second + 1;
		if (res >= mod_mask) {
			res = res % mod_mask;
		}
	}
	--res; // don't count zero length subsequence
	std::cout << res << '\n';
}
