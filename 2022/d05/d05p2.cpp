#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::vector<std::string> v = {
        "WRF", "THMCDVWP",
        "PMZNL", "JCHR",
        "CPGHQTB", "GCWLFZ",
        "WVLQZJGC", "PNRFWTVC",
        "JWHGRSV"
    };
    std::string s;
    int x1, x2, x3;
    for (int i = 0; i < 10; i++) std::getline(std::cin, s);
    while (std::getline(std::cin, s)) {
        std::stringstream ss(s);
        ss >> s >> x1 >> s >> x2 >> s >> x3; x2--; x3--;
        v[x3] = v[x3] + v[x2].substr(v[x2].length() - x1);
        v[x2] = v[x2].substr(0, v[x2].length() - x1);
    }
    for (auto i : v) std::cout << i.back();
    std::cout << std::endl;
}
