#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<int, int> u;
    std::vector<char> v(240, '.');
    std::string s;
    int x = 1, input;
    bool running = 0;
    for (int i = 1; ; i++) {
        if (running) running = 0;
        else if (!running) {
            if (!(std::cin >> s)) break;
            if (s == "addx") {
                std::cin >> input;
                u[i + 2] = input;
                running = 1;
            }
        }
        if (u.find(i) != u.end()) x += u[i];
        if (x - 1 <= (i - 1) % 40 && (i - 1) % 40 <= x + 1) v[i - 1] = '#';
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 40; j++) std::cout << v[i * 40 + j];
        std::cout << std::endl;
    }
}
