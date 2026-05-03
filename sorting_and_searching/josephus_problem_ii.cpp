#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

int main() {
	// https://www.geeksforgeeks.org/cpp/ordered-set-gnu-c-pbds/
	typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,std::less<int>,__gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> indexed_set;

	int n;
	int skip;
	std::cin >> n >> skip;
	int jump = skip + 1;

	indexed_set remaining;
	for (int i = 0; i < n; ++i) {
		remaining.insert(i);
	}

	int remaining_count = n;
	int cur_i = 0;
	
	for (int i = 0; i < n - 1; ++i) {
		cur_i = (cur_i + jump - 1) % remaining_count; // -1 since after erase our old cur_i is already pointing to next so we already jumped 1
		auto cur = remaining.find_by_order(cur_i);
		std::cout << *cur + 1 << ' ';
		remaining.erase(cur);
		--remaining_count;
	}
	// do last time outside loop to avoid mod 0 calculation (and print nicely)
	std::cout << *remaining.find_by_order(0) + 1 << '\n';
}
