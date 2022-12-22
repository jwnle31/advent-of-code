#include <iostream>
#include <vector>

void move_down(std::vector<std::pair<int, int>>& p, std::vector<std::vector<bool>>& chamber) {
    for (auto i : p) {
        if (!i.first || chamber[i.first - 1][i.second]) {
            return;
        }
    }
    for (size_t i = 0; i < p.size(); i++) p[i].first--;
}

void move_right(std::vector<std::pair<int, int>>& p, std::vector<std::vector<bool>>& chamber) {
    for (auto i : p) {
        if (i.second == 6 || chamber[i.first][i.second + 1]) return;
    }
    for (size_t i = 0; i < p.size(); i++) p[i].second++;
}

void move_left(std::vector<std::pair<int, int>>& p, std::vector<std::vector<bool>>& chamber) {
    for (auto i : p) {
        if (!i.second || chamber[i.first][i.second - 1]) return;
    }
    for (size_t i = 0; i < p.size(); i++) p[i].second--;
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<std::vector<std::pair<int, int>>> b = {
        {{0, 2}, {0, 3}, {0, 4}, {0, 5}},
        {{2, 3}, {1, 2}, {1, 3}, {1, 4}, {0, 3}},
        {{2, 4}, {1, 4}, {0, 2}, {0, 3}, {0, 4}},
        {{3, 2}, {2, 2}, {1, 2}, {0, 2}},
        {{1, 2}, {1, 3}, {0, 2}, {0, 3}}
    };
    std::vector<std::vector<bool>> chamber(3, std::vector<bool>(7, 0));
    int idx = 0, highest = -1;
    for (int i = 0; i < 2022; i++) {
        auto bi = b[i % 5];
        int extra_row = highest + 8 - chamber.size();
        for (int j = 0; j < extra_row; j++) chamber.push_back(std::vector<bool>(7, 0));
        for (size_t j = 0; j < bi.size(); j++) bi[j].first += highest + 4;
        while (true) {
            if (s[idx] == '<') move_left(bi, chamber);
            else move_right(bi, chamber);
            idx = (idx + 1) % s.size();
            auto p = bi[0];
            move_down(bi, chamber);
            if (p == bi[0]) {
                for (auto j : bi) chamber[j.first][j.second] = 1;
                highest = std::max(highest, bi[0].first);
                break;
            }
        }
    }
    std::cout << highest + 1 << std::endl;
}
