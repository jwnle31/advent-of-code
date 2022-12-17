#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long

bool compare_pair(const std::pair<int, int> p1, const std::pair<int, int> p2) {
    return (p1.first < p2.first) ? 1 : 0; 
}

int main() {
    ll side = 4000000, sx, sy, bx, by;
    std::string s;
    std::vector<std::pair<ll, ll>> v, beacon, sensor;
    while (std::getline(std::cin, s)) {
        sscanf(s.c_str(), "Sensor at x=%lld, y=%lld: closest beacon is at x=%lld, y=%lld", &sx, &sy, &bx, &by);
        sensor.push_back({sx, sy});
        beacon.push_back({bx, by});
    }
    int size = beacon.size();
    for (ll i = 0; i <= side; i++) {
        v.clear();
        for (int j = 0; j <= size; j++) {
            sx = sensor[j].first; sy = sensor[j].second;
            bx = beacon[j].first; by = beacon[j].second;
            int d = abs(sx - bx) + abs(sy - by) - abs(i - sy);
            int x1 = (sx - d < 0) ? 0 : sx - d;
            int x2 = (sx + d > side) ? side : sx + d;
            if (d >= 0 && x2 >= x1) v.push_back({x1, x2});
        }
        sort(v.begin(), v.end(), compare_pair);
        int r = -1;
        for (auto p : v) {
            if (p.first > r + 1) {
                std::cout << (p.first - 1) * side + i << std::endl;
                return 0;
            } else if (p.second > r) r = p.second;
        }
    }
}
