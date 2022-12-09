#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<std::pair<int, int>> v(10, std::make_pair(0, 0));
    std::unordered_map<int, std::set<int>> u;
    char c;
    int x;
    while (std::cin >> c >> x) {
        for (int i = 0; i < x; i++) {
            if (c == 'L') v[0].first--;
            else if (c == 'U') v[0].second++;
            else if (c == 'R') v[0].first++;
            else v[0].second--;
            for (int j = 0; j < 9; j++) {
                if (abs(v[j].first - v[j + 1].first) + abs(v[j].second - v[j + 1].second) == 4) {
                    if (v[j].second > v[j + 1].second) {
                        if (v[j].first > v[j + 1].first) v[j + 1].first++;
                        else v[j + 1].first--;
                        v[j + 1].second++;
                    } else if (v[j + 1].second > v[j].second) {
                        if (v[j].first == v[j + 1].first + 2) v[j + 1].first++;
                        else v[j + 1].first--;
                        v[j + 1].second--;
                    }
                } else if (v[j + 1].first - v[j].first == 2) {
                    v[j + 1].first = v[j].first + 1;
                    v[j + 1].second = v[j].second;
                } else if (v[j].second - v[j + 1].second == 2) {
                    v[j + 1].first = v[j].first;
                    v[j + 1].second = v[j].second - 1;
                } else if (v[j].first - v[j + 1].first == 2) {
                    v[j + 1].first = v[j].first - 1;
                    v[j + 1].second = v[j].second;
                } else if (v[j + 1].second - v[j].second == 2) {
                    v[j + 1].first = v[j].first;
                    v[j + 1].second = v[j].second + 1;
                }
            }
            u[v[9].first].insert(v[9].second);
        }
    }
    int count = 0;
    for (auto& s : u) count += s.second.size();
    std::cout << count << std::endl;
}
