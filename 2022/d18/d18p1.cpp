#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int a[3];
    std::string s;
    std::unordered_set<std::string> u;
    int count = 0;
    int dir[2] = {-1, 1};
    while (std::getline(std::cin, s)) {
        u.insert(s);
        sscanf(s.c_str(), "%d,%d,%d", &a[0], &a[1], &a[2]);
        int connected = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                a[i] += dir[j];
                if (u.find(std::to_string(a[0]) + ',' + std::to_string(a[1]) + ',' + std::to_string(a[2])) != u.end()) {
                    connected++;
                }
                a[i] -= dir[j];
            }
        }
        count += 6 - 2 * connected;
    }
    std::cout << count << std::endl;
}
