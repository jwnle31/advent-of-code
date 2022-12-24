#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define ll long long

int main() {
    std::unordered_map<std::string, ll> um;
    std::unordered_set<std::string> us;
    std::string s;
    while (std::getline(std::cin, s)) {
        if (s.length() == 17 && !isdigit(s[11])) us.insert(s);
        else um[s.substr(0, 4)] = std::stoll(s.substr(6));
    }
    while (!us.empty()) {
        auto it = us.begin();
        while (it != us.end()) {
            std::string m = (*it).substr(0, 4);
            std::string m1 = (*it).substr(6, 4);
            std::string m2 = (*it).substr(13, 4);
            if (um.find(m1) != um.end() && um.find(m2) != um.end()) {
                if ((*it)[11] == '+') um[m] = um[m1] + um[m2];
                else if ((*it)[11] == '-') um[m] = um[m1] - um[m2];
                else if ((*it)[11] == '*') um[m] = um[m1] * um[m2];
                else um[m] = um[m1] / um[m2];
                it = us.erase(it);
            } else {
                ++it;
            }
        }
    }
    std::cout << um["root"] << std::endl;
}
