#include <iostream>
#include <set>
#include <unordered_map>

int main() {
    std::pair<int, int> h = { 0, 0 }, t = { 0, 0 };
    std::unordered_map<int, std::set<int>> u;
    char c;
    int x;
    while (std::cin >> c >> x) {
        for (int i = 0; i < x; i++) {
            if (c == 'L') {
                if (t.first - --h.first == 2) {
                    t.first = h.first + 1;
                    t.second = h.second;
                }
            } else if (c == 'U') {
                if (++h.second - t.second == 2) {
                    t.first = h.first;
                    t.second = h.second - 1;
                }
            } else if (c == 'R') {
                if (++h.first - t.first == 2) {
                    t.first = h.first - 1;
                    t.second = h.second;
                }
            } else {
                if (t.second - --h.second == 2) {
                    t.first = h.first;
                    t.second = h.second + 1;
                }
            }
            u[t.first].insert(t.second);
        }
    }
    int count = 0;
    for (auto& s : u) count += s.second.size();
    std::cout << count << std::endl;
}
