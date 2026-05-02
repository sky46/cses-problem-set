#include <iostream>
#include <set>
#include <algorithm>

int main();

int main() {
    int ticket_count; //n
    int customer_count; //m
    std::cin >> ticket_count >> customer_count;
    
    std::multiset<int> tickets;

    for (int i = 0; i < ticket_count; ++i) {
        int ticket;
        std::cin >> ticket;
        tickets.insert(ticket);
    }
    for (int i = 0; i < customer_count; ++i) {
        int max_price;
        std::cin >> max_price;
        auto max_ticket = tickets.upper_bound(max_price);
        if (max_ticket == tickets.begin()) {
            // smallest ticket price is more than max_price
            std::cout << "-1";
        } else {
            // max_ticket currently is first greater than so decrease by 1 to get greatest that is <= max_price
            std::cout << *(--max_ticket);
            tickets.erase(max_ticket);
        }
        std::cout << '\n';
    }
}
