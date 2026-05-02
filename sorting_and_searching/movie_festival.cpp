#include <iostream>
#include <vector> 
#include <algorithm>
#include <utility>

bool end_earlier_than(const std::pair<int,int>& movie1, const std::pair<int,int>& movie2) {
    return movie1.second < movie2.second;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> movies(n); // start, end 
    for (int i = 0; i < n; ++i) {
        std::cin >> movies[i].first >> movies[i].second;
    }
    std::sort(movies.begin(), movies.end(), end_earlier_than);
    int watched = 0;
    int current_time = 0;
    for (auto movie : movies) {
        if (movie.first >= current_time) {
            ++watched;
            current_time = movie.second;
        }
    }
    std::cout << watched;
}