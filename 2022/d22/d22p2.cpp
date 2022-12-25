#include <iostream>
#include <vector>

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
    for (int i = 0; i < w; i++) {
        if (grid[0][i] == '.') {
            cur.second = i;
            break;
        }
    }
    while (std::cin >> x) {
        while (x) {
            std::pair<int, int> next;
            int ndir;
            if (cur.first == 0 && cur.second >= 50 && cur.second < 100 && dir == 3) {
                next = {cur.second + 100, 0};
                ndir = 0;
            } else if (cur.first >= 150 && cur.first < 200 && cur.second == 0 && dir == 2) {
                next = {0, cur.first - 100};
                ndir = 1;
            } else if (cur.first >= 0 && cur.first < 50 && cur.second == 50 && dir == 2) {
                next = {149 - cur.first, 0};
                ndir = 0;
            } else if (cur.first >= 100 && cur.first < 150 && cur.second == 0 && dir == 2) {
                next = {149 - cur.first, 50};
                ndir = 0;
            } else if (cur.first >= 50 && cur.first < 100 && cur.second == 50 && dir == 2) {
                next = {100, cur.first - 50};
                ndir = 1;
            } else if (cur.first == 100 && cur.second >= 0 && cur.second < 50 && dir == 3) {
                next = {cur.second + 50, 50};
                ndir = 0;
            } else if (cur.first == 0 && cur.second >= 100 && cur.second < 150 && dir == 3) {
                next = {199, cur.second - 100};
                ndir = 3;
            } else if (cur.first == 199 && cur.second >= 0 && cur.second < 50 && dir == 1) {
                next = {0, cur.second + 100};
                ndir = 1;
            } else if (cur.first >= 0 && cur.first < 50 && cur.second == 149 && dir == 0) {
                next = {149 - cur.first, 99};
                ndir = 2;
            } else if (cur.first >= 100 && cur.first < 150 && cur.second == 99 && dir == 0) {
                next = {149 - cur.first, 149};
                ndir = 2;
            } else if (cur.first == 49 && cur.second >= 100 && cur.second < 150 && dir == 1) {
                next = {cur.second - 50, 99};
                ndir = 2;
            } else if (cur.first >= 50 && cur.first < 100 && cur.second == 99 && dir == 0) {
                next = {49, cur.first + 50};
                ndir = 3;
            } else if (cur.first == 149 && cur.second >= 50 && cur.second < 100 && dir == 1) {
                next = {cur.second + 100, 49};
                ndir = 2;
            } else if (cur.first >= 150 && cur.first < 200 && cur.second == 49 && dir == 0) {
                next = {149, cur.first - 100};
                ndir = 3;
            } else {
                next = {cur.first + dira[dir].first, cur.second + dira[dir].second};
                ndir = dir;
            }
            int nextf = next.first, nexts = next.second;
            if (grid[nextf][nexts] == '#') break;
            else x--;
            cur = next;
            dir = ndir;
        }
        if (!(std::cin >> c)) break;
        if (c == 'R') dir = (dir + 1) % 4;
        else dir = (dir + 3) % 4;
    }
    std::cout << (cur.first + 1) * 1000 + (cur.second + 1) * 4 + dir << std::endl;
}
