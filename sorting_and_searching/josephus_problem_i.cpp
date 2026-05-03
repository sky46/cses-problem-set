#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<bool> removed(n);
	int cur = 1; // cur is zero-indexed, starting on second child.
	for (int i = 0; i < n - 1; ++i) {
		if (cur >= n) {
			cur = cur % n;
		}
		removed[cur] = true;
		std::cout << cur + 1 << ' ';
		for (int j = 0; j < 2; ++j) {// do twice
			do {
				cur = (cur == n - 1) ? 0 : cur + 1;
			} while (removed[cur]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!removed[i]) {
			std::cout << i + 1 << '\n';
			removed[i] = true;
			break;
		}
	}
}
