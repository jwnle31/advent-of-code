#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    std::string s;
    std::vector<int> v; 
    std::unordered_map<int, int> u;
    bool next;
    int id = 0;
    while (std::cin >> s) {
        if (s == "$" || next) {
            if (!next) std::cin >> s;
            next = 0;
            if (s == "ls") {
                while (std::cin >> s) {
                    if (s == "dir") {
                        std::cin >> s;
                    } else if (s != "$") {
                        int x = std::stoi(s);
                        std::cin >> s;
                        for (auto i : v) u[i] += x;
                    } else {
                        break;
                    }
                }
                next = 1;
            } else if (s == "cd") {
                std::cin >> s;
                if (s == "..") v.pop_back();
                else v.push_back(id++);
            }
        }
    }
    int ans = 70000000;
    int diff = u[0] - 40000000;
    for (auto& i : u) if (i.second > diff && i.second < ans) ans = i.second;
    std::cout << ans << std::endl;
}
