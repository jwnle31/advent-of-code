#include <iostream>
#include <vector>

int pos_mod(int m, int n) {
    return (m % n + n) % n;
}

int main() {
    std::vector<std::string> grid;
    std::string s;
    int w = 0, h;
    while (std::getline(std::cin, s)) {
        if (s.empty()) break;
        grid.push_back(s);
        if ((int)s.size() > w) w = s.size();
    }
    h = grid.size();
    for (int i = 0; i < h; i++) {
        if ((int)grid[i].size() != w) grid[i] += std::string(w - grid[i].size(), ' ');
    }
    int x, dir = 0;
    char c;
    std::pair<int, int> cur = {0, 0}, dira[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (std::cin >> x) {
        while (x) {
            int nextf = pos_mod(cur.first + dira[dir].first, h);
            int nexts = pos_mod(cur.second + dira[dir].second, w);
            while (grid[nextf][nexts] == ' ') {
                nextf = pos_mod(nextf + dira[dir].first, h);
                nexts = pos_mod(nexts + dira[dir].second, w);
            }
            if (grid[nextf][nexts] == '#') break;
            else if (grid[nextf][nexts] == '.') x--;
            cur = {nextf, nexts};
        }
        if (!(std::cin >> c)) break;
        if (c == 'R') dir = (dir + 1) % 4;
        else dir = (dir + 3) % 4;
    }
    std::cout << (cur.first + 1) * 1000 + (cur.second + 1) * 4 + dir << std::endl;
}
