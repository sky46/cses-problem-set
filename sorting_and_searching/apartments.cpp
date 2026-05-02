#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    int m;
    int k;
    std::cin >> n >> m >> k;
    std::vector<int> applicants(n);
    std::vector<int> apartments(m);
    for (int& app : applicants) {
        std::cin >> app;
    }
    for (int& apart : apartments) {
        std::cin >> apart;
    }
    std::sort(applicants.begin(), applicants.end());
    std::sort(apartments.begin(), apartments.end());
    auto appl{applicants.begin()};
    auto apar{apartments.begin()};
    int accepted{0};
    while (appl != applicants.end() && apar != apartments.end()) {
        if (*apar - k <= *appl && *appl <= *apar + k) {
            ++accepted;
            ++apar;
            ++appl;
        } else if (*apar < *appl) {
            ++apar;
        } else {
            ++appl;
        }
    }
    std::cout << accepted << '\n';
}