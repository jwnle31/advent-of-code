#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

int main() {
    std::unordered_map<int, std::unordered_set<int>> u;
    int px, py, x, y;
    char c;
    std::string s;
    int bottom = 0;
    while (std::getline(std::cin, s)) {
        std::stringstream ss(s);
        ss >> px >> c >> py >> c >> c;
        while (ss >> x >> c >> y) {
            if (y > bottom) bottom = y;
            if (x > px) {
                for (int i = px; i <= x; i++) u[i].insert(y);
            } else if (x < px) {
                for (int i = x; i <= px; i++) u[i].insert(y);
            } else if (y > py) {
                for (int i = py; i <= y; i++) u[x].insert(i);
            } else if (y < py) {
                for (int i = y; i <= py; i++) u[x].insert(i);
            }
            if (!ss) break;
            else ss >> c >> c;
            px = x; py = y;
        }
    }
    int floor = bottom + 1;
    for (int i = 1; ; i++) {
        x = 500, y = 0;
        while (true) {
            if (y == floor) {
                u[x].insert(y);
                break;
            }
            if (u[x].find(y + 1) == u[x].end()) {
                y++;
            } else if (u[x - 1].find(y + 1) == u[x - 1].end()) {
                x--; y++;
            } else if (u[x + 1].find(y + 1) == u[x + 1].end()) {
                x++; y++;
            } else {
                u[x].insert(y);
                if (x == 500 && y == 0) {
                    std::cout << i << std::endl;
                    return 0;
                }
                break;
            }
        }
    }
}
