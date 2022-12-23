#include <iostream>
#include <limits>
#include <queue>
#include <unordered_set>
#include <vector>

int main() {
    int imin = std::numeric_limits<int>::min();
    int imax = std::numeric_limits<int>::max();
    std::vector<int> p(3);
    int minp[3] = {imax, imax, imax}, maxp[3] = {imin, imin, imin};
    std::string s;
    std::unordered_set<std::string> u;
    while (std::getline(std::cin, s)) {
        sscanf(s.c_str(), "%d,%d,%d", &p[0], &p[1], &p[2]);
        for (int i = 0; i < 3; i++) {
            if (p[i] > maxp[i]) maxp[i] = p[i];
            if (p[i] < minp[i]) minp[i] = p[i];
        }
        u.insert(s);
    }
    for (int i = 0; i < 3; i++) {
        minp[i]--; maxp[i]++;
        p[i] = minp[i];
    }
    int count = 0;
    int dir[2] = {-1, 1};
    int size[3];
    for (int i = 0; i < 3; i++) size[i] = maxp[i] - minp[i] + 1;
    std::vector<std::vector<std::vector<bool>>> v(size[0], std::vector<std::vector<bool>>(size[1], std::vector<bool>(size[2], 0)));
    std::queue<std::vector<int>> q;
    q.push(p);
    v[p[0] - minp[0]][p[1] - minp[1]][p[2] - minp[2]] = 1;
    while (!q.empty()) {
        p = q.front(); q.pop();
        for (int i = 0; i < 3; i++) {
            for (int d : dir) {
                int op[3];
                p[i] += d;
                for (int i = 0; i < 3; i++) op[i] = p[i] - minp[i];
                bool is_lava = u.find(std::to_string(p[0]) + ',' + std::to_string(p[1]) + ',' + std::to_string(p[2])) != u.end();
                if (!is_lava && p[i] >= minp[i] && p[i] <= maxp[i] && !v[op[0]][op[1]][op[2]]) {
                    q.push(p);
                    v[op[0]][op[1]][op[2]] = 1;
                }
                if (is_lava) count++;
                p[i] -= d;
            }
        }
    }
    std::cout << count << std::endl;
}
