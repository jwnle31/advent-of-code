#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <vector>

int main() {
    std::vector<std::vector<char>> grid;
    std::string s;
    char c;
    int ec, count = 0;
    while (std::getline(std::cin, s)) {
        std::stringstream ss(s);
        std::vector<char> v;
        while (ss >> c) {
            if (c == 'S') {
                c = 'a';
            } else if (c == 'E') {
                ec = count;
                c = 'z';
            }
            v.push_back(c);
            count++;
        }
        grid.push_back(v);
    }
    int w = grid[0].size();
    int h = grid.size();
    std::pair<int, int> dest = { ec / w, ec % w };
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, std::numeric_limits<int>::max()));
    std::queue<std::pair<int, int>> q;
    q.push(dest);
    dist[dest.first][dest.second] = 0;
    std::pair<int, int> source;
    while (!q.empty()) {
        source = q.front();
        if (grid[source.first][source.second] == 'a') break;
        q.pop();
        int x = source.first;
        int y = source.second;
        std::vector<std::pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (auto d : dir) {
            int new_x = x + d.first;
            int new_y = y + d.second;
            if (new_x >= 0 && new_x < h && new_y >= 0 && new_y < w && 
                grid[new_x][new_y] + 1 >= grid[x][y] && 
                dist[x][y] + 1 < dist[new_x][new_y]) {
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push({ new_x, new_y });
            }
        }
    }
    std::cout << dist[source.first][source.second] << std::endl;
}
