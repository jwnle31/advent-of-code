#include <iostream>
#include <queue>
#include <set>
#include <vector>

int gcd(int m, int n) {
    if (!n) return m;
    return gcd(n, m % n);
}

int lcm(int m, int n) {
    return (m * gcd(m, n)) * n;
}

int pos_mod(int m, int n) {
    return (m % n + n) % n;
}

int main() {
    std::string s;
    std::set<std::pair<int, int>> rb, db, lb, ub;
    std::vector<std::string> grid;
    int j = 0;
    while (std::getline(std::cin, s)) {
        grid.push_back(s);
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '>') rb.insert({j, i});
            else if (s[i] == 'v') db.insert({j, i});
            else if (s[i] == '<') lb.insert({j, i});
            else if (s[i] == '^') ub.insert({j, i});
        }
        j++;
    }
    int r = j - 2, c = grid[0].size() - 2;
    int cyc = lcm(r, c);
    std::set<std::vector<int>> visited;
    std::queue<std::vector<int>> q;
    std::vector<int> start = {0, 1, 0};
    q.push(start);
    visited.insert(start);
    std::vector<std::pair<int, int>> dir = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<std::pair<int, int>> vv = {{r + 1, c}, {0, 1}, {r + 1, c}};
    std::vector<int> check;
    for (auto p : vv) {
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            if (v[0] == p.first && v[1] == p.second) {
                check = v;
                break;
            }
            for (auto d : dir) {
                std::vector<int> new_v = {v[0] + d.first, v[1] + d.second, v[2] + 1};
                if (visited.find(new_v) == visited.end() 
                    && ((new_v[0] == r + 1 && new_v[1] == c) || (new_v[0] == 0 && new_v[1] == 1) 
                        || (new_v[0] > 0 && new_v[0] < r + 1 && new_v[1] > 0 && new_v[1] < c + 1))
                    && rb.find({new_v[0], pos_mod(new_v[1] - new_v[2] - 1, cyc) % c + 1}) == rb.end()
                    && db.find({pos_mod(new_v[0] - new_v[2] - 1, cyc) % r + 1, new_v[1]}) == db.end()
                    && lb.find({new_v[0], pos_mod(new_v[1] + new_v[2] - 1, cyc) % c + 1}) == lb.end()
                    && ub.find({pos_mod(new_v[0] + new_v[2] - 1, cyc) % r + 1, new_v[1]}) == ub.end()) {
                    visited.insert(new_v);
                    q.push(new_v);
                }
            }
        }
        q = {};
        visited.clear();
        q.push(check);
    }
    std::cout << check[2] << std::endl;
}
