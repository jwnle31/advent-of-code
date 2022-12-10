#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<int, int> u;
    std::vector<char> v(240, '.');
    std::string s;
    int x = 1, sum = 0, input;
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
        if ((i + 20) % 40 == 0) sum += i * x;
    }
    std::cout << sum << std::endl;
}
