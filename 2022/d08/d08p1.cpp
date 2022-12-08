#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::vector<std::vector<int>> table;
    std::string s;
    char c;
    while (std::getline(std::cin, s)) {
        std::stringstream ss(s);
        std::vector<int> v;
        while (ss >> c) v.push_back(c - '0');
        table.push_back(v);
    }
    int side = table[0].size();
    std::vector<int> tall(4, -1);
    std::vector<std::vector<bool>> visible(side, std::vector<bool>(side, 0));
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (table[i][j] > tall[0]) {
                tall[0] = table[i][j];
                visible[i][j] = 1;
            }
            if (table[i][side - 1 - j] > tall[1]) {
                tall[1] = table[i][side - 1 - j];
                visible[i][side - 1 - j] = 1;
            }
            if (table[j][i] > tall[2]) {
                tall[2] = table[j][i];
                visible[j][i] = 1;
            }
            if (table[side - 1 - j][i] > tall[3]) {
                tall[3] = table[side - 1 - j][i];
                visible[side - 1 - j][i] = 1;
            }
        }
        std::fill(tall.begin(), tall.end(), -1);
    }
    int count = 0;
    for (auto r : visible) for (auto x : r) if (x) count++;
    std::cout << count << std::endl;
}
