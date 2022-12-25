#include <iostream>
#include <limits>
#include <map>
#include <set>

int main() {
    std::set<std::pair<int, int>> sp;
    std::map<std::pair<int, int>, std::pair<int, int>> ready;
    std::map<std::pair<int, int>, int> count;
    std::string s;
    int j = 0;
    while (std::getline(std::cin, s)) {
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '#') sp.insert({i, j});
        }
        j++;
    }
    for (int i = 0; i < 10; i++) {
        for (auto p : sp) {
            int pf = p.first, ps = p.second;
            int comp[8];
            comp[0] = sp.find({pf, ps - 1}) == sp.end();
            comp[1] = sp.find({pf + 1, ps - 1}) == sp.end();
            comp[2] = sp.find({pf + 1, ps}) == sp.end();
            comp[3] = sp.find({pf + 1, ps + 1}) == sp.end();
            comp[4] = sp.find({pf, ps + 1}) == sp.end();
            comp[5] = sp.find({pf - 1, ps + 1}) == sp.end();
            comp[6] = sp.find({pf - 1, ps}) == sp.end();
            comp[7] = sp.find({pf - 1, ps - 1}) == sp.end();
            std::pair<int, int> d, dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
            bool check[4];
            check[0] = comp[7] && comp[0] && comp[1];
            check[1] = comp[3] && comp[4] && comp[5];
            check[2] = comp[5] && comp[6] && comp[7];
            check[3] = comp[1] && comp[2] && comp[3];
            if (check[0] && check[1] && check[2] && check[3]) continue;
            if (check[i % 4]) d = dir[i % 4];
            else if (check[(i + 1) % 4]) d = dir[(i + 1) % 4];
            else if (check[(i + 2) % 4]) d = dir[(i + 2) % 4];
            else if (check[(i + 3) % 4]) d = dir[(i + 3) % 4];
            else continue;
            std::pair<int, int> rp = {p.first + d.first, p.second + d.second};
            ready[rp] = p;
            count[rp]++;
        }
        for (auto &[pf, ps] : ready) {
            if (count[pf] == 1) {
                sp.erase(ps);
                sp.insert(pf);
            }
        }
        ready.clear();
        count.clear();
    }
    int imax = std::numeric_limits<int>::max();
    int imin = std::numeric_limits<int>::min();
    int minc[2] = {imax, imax}, maxc[2] = {imin, imin};
    for (auto p : sp) {
        if (p.first < minc[0]) minc[0] = p.first;
        if (p.second < minc[1]) minc[1] = p.second;
        if (p.first > maxc[0]) maxc[0] = p.first;
        if (p.second > maxc[1]) maxc[1] = p.second;
    }
    std::cout << (maxc[0] - minc[0] + 1) * (maxc[1] - minc[1] + 1) - sp.size() << std::endl;
}
