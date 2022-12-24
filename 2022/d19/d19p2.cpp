#include <iostream>
#include <queue>
#include <set>
#include <vector>

int bfs(int ore_rc, int clay_rc, std::pair<int, int> obs_rc, std::pair<int, int> geo_rc, int t) {
    std::vector<int> s = {0, 0, 0, 0, 1, 0, 0, 0, t};
    int max_geode = 0;
    std::queue<std::vector<int>> q;
    std::set<std::vector<int>> visited;
    q.push(s);
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        max_geode = std::max(max_geode, v[3]);
        int max_rc = std::max(ore_rc, std::max(clay_rc, std::max(obs_rc.first, geo_rc.first)));
        v[4] = std::min(v[4], max_rc);
        v[5] = std::min(v[5], obs_rc.second);
        v[6] = std::min(v[6], geo_rc.second);
        v[0] = std::min(v[0], v[8] * (max_rc - v[4]) + v[4]);
        v[1] = std::min(v[1], v[8] * (obs_rc.second - v[5]) + v[5]);
        v[2] = std::min(v[2], v[8] * (geo_rc.second -  v[6]) + v[6]);
        if (!v[8] || visited.find(v) != visited.end()) continue;
        visited.insert(v);
        v[8]--;
        q.push({v[0] + v[4], v[1] + v[5], v[2] + v[6], v[3] + v[7], v[4], v[5], v[6], v[7], v[8]});
        if (v[0] >= ore_rc) {
            q.push({v[0] + v[4] - ore_rc, v[1] + v[5], v[2] + v[6], v[3] + v[7], v[4] + 1, v[5], v[6], v[7], v[8]});
        }
        if (v[0] >= clay_rc) {
            q.push({v[0] + v[4] - clay_rc, v[1] + v[5], v[2] + v[6], v[3] + v[7], v[4], v[5] + 1, v[6], v[7], v[8]});
        }
        if (v[0] >= obs_rc.first && v[1] >= obs_rc.second) {
            q.push({v[0] + v[4] - obs_rc.first, v[1] + v[5] - obs_rc.second, v[2] + v[6], v[3] + v[7], v[4], v[5], v[6] + 1, v[7], v[8]});
        }
        if (v[0] >= geo_rc.first && v[2] >= geo_rc.second) {
            q.push({v[0] + v[4] - geo_rc.first, v[1] + v[5], v[2] + v[6] - geo_rc.second, v[3] + v[7], v[4], v[5], v[6], v[7] + 1, v[8]});
        }
    }
    return max_geode;
}

int main() {
    std::string s;
    int ans = 1;
    for (int i = 0; i < 3; i++) {
        std::getline(std::cin, s);
        int blueprint, ore_rc, clay_rc;
        std::pair<int, int> obs_rc, geo_rc;
        sscanf(s.c_str(), "Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.", &blueprint, &ore_rc, &clay_rc, &obs_rc.first, &obs_rc.second, &geo_rc.first, &geo_rc.second);
        int max_geode = bfs(ore_rc, clay_rc, obs_rc, geo_rc, 32);
        ans *= max_geode;
    }
    std::cout << ans << std::endl;
}
