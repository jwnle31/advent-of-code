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
    std::vector<std::vector<int>> score(side, std::vector<int>(side, 0));
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            int a[4] = { 0 };
            for (int k = j + 1; k < side; k++) {
                a[0]++;
                if (table[i][j] <= table[i][k]) break;
            }
            for (int k = j - 1; k >= 0; k--) {
                a[1]++;
                if (table[i][j] <= table[i][k]) break;
            }
            for (int k = i + 1; k < side; k++) {
                a[2]++;
                if (table[i][j] <= table[k][j]) break;
            }
            for (int k = i - 1; k >= 0; k--) {
                a[3]++;
                if (table[i][j] <= table[k][j]) break;
            }
            score[i][j] = a[0] * a[1] * a[2] * a[3];
        }
    }
    int max = 0;
    for (auto r : score) for (auto x : r) if (x > max) max = x;
    std::cout << max << std::endl;
}
