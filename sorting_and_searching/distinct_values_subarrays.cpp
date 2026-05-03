#include <iostream>
#include <set>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	
	std::set<int> cur;
	long long count = 0;
	int l = 0;
	int r = 0;
	while (r < n) {
		auto prev = cur.find(arr[r]);
		if (prev != cur.end()) {
			while (arr[l] != *prev) {
				cur.erase(arr[l++]);
			}
			cur.erase(arr[l++]);
		}
		count += 1 + cur.size();
		cur.insert(arr[r]);
		++r;
	}
	std::cout << count << '\n';
}
