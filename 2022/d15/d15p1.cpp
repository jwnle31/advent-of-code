#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

bool compare_pair(const std::pair<int, int> p1, const std::pair<int, int> p2) {
    return (p1.first < p2.first) ? 1 : 0; 
}

int main() {
    int row = 2000000, sx, sy, bx, by;
    std::string s;
    std::vector<std::pair<int, int>> v;
    std::unordered_set<int> u;
    while (getline(std::cin, s)) {
        sscanf(s.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &sx, &sy, &bx, &by);
        if (by == row) u.insert(bx);
        int d = abs(sx - bx) + abs(sy - by) - abs(row - sy);
        int x1 = sx - d;
        int x2 = sx + d;
        if (d >= 0 && x2 >= x1) v.push_back({x1, x2});
    }
    sort(v.begin(), v.end(), compare_pair);
    int r = std::numeric_limits<int>::min(), count = 0;
    for (auto p : v) {
        if (p.first > r + 1) {
            count += p.second - p.first + 1;
            for (int i = p.first; i <= p.second; i++) {
                if (u.find(i) != u.end()) count--;
            }
            r = p.second;
        } else if (p.second > r) {
            count += p.second - r;
            for (int i = r + 1; i <= p.second; i++) {
                if (u.find(i) != u.end()) count--;
            }
            r = p.second;
        }

    }
    std::cout << count << std::endl;
}
