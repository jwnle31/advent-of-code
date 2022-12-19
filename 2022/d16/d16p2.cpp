#include <bitset>
#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void dfs(std::vector<std::vector<int>>& v, std::vector<int>& flow, std::vector<int>& nzp,
         std::string opened, int node, int time, std::unordered_map<std::string, int>& m, int p) {
    opened[node] = '1';
    for (auto i : nzp) {
        if (opened[i] == '0') {
            int new_time = time - 1 - v[node][i];
            if (new_time > 0) {
                std::string s = opened;
                s[i] = '1';
                int new_p = time * flow[node] + p;
                int val = new_time * flow[i] + new_p;
                if (m.find(s) != m.end()) {
                    if (val > m[s]) m[s] = val;
                } else {
                    m[s] = val;
                }
                dfs(v, flow, nzp, opened, i, new_time, m, new_p);
            }
        }
    }
}

int main() {
    const int imax = std::numeric_limits<int>::max();
    std::string s;
    std::unordered_map<std::string, int> id;
    std::unordered_map<int, std::unordered_set<std::string>> adj;
    std::unordered_map<std::string, int> m;
    std::vector<int> flow;
    std::vector<int> nzp;
    int idx = 0, start;
    while (std::getline(std::cin, s)) {
        std::stringstream ss(s);
        ss >> s >> s;
        if (s == "AA") start = idx;
        id[s] = idx;
        ss >> s >> s >> s;
        int p = stoi(s.substr(5, s.size() - 1));
        flow.push_back(p);
        if (p) nzp.push_back(idx);
        ss >> s >> s >> s >> s;
        while (ss >> s) {
            if (s[s.size() - 1] == ',') s.pop_back();
            adj[idx].insert(s);
        }
        idx++;
    }
    std::vector<std::vector<int>> v(idx, std::vector<int>(idx, imax));
    for (int i = 0; i < idx; i++) {
        v[i][i] = 0;
        for (auto node : adj[i]) v[i][id[node]] = 1;
    }
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < idx; j++) {
            for (int k = 0; k < idx; k++) {
                if (v[j][i] != imax && v[i][k] != imax) {
                    v[j][k] = std::min(v[j][k], v[j][i] + v[i][k]);
                }
            }
        }
    }
    std::string opened(idx, '0');
    dfs(v, flow, nzp, opened, start, 26, m, 0);
    std::vector<std::string> e;
    for (auto &[i, j] : m) e.push_back(i);
    int size = e.size();
    int max = 0;
    std::string s1, s2;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            std::bitset<500> b1(e[i]); b1[idx - start - 1] = 0;
            std::bitset<500> b2(e[j]); b2[idx - start - 1] = 0;
            if ((b1 & b2) == 0) {
                int cur = m[e[i]] + m[e[j]];
                if (cur > max) {
                    max = cur;
                    s1 = e[i];
                    s2 = e[j];
                }
            }
        }
    }
    std::cout << max << std::endl;
}
