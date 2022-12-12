#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

int monkey(std::string f, int x) {
    std::string s = f.substr(2);
    if (s == "old") return x * x;
    else if (f[0] == '+') return x + std::stoi(s);
    else if (f[0] == '*') return x * std::stoi(s);
    return 0;
}

int main() {
    std::vector<std::queue<int>> v;
    std::vector<std::string> func;
    std::vector<int> div;
    std::vector<std::pair<int, int>> t;
    std::string s;
    int x;
    char c;
    while (std::getline(std::cin, s)) {
        std::getline(std::cin, s);
        std::stringstream ss(s);
        std::queue<int> q;
        ss >> s >> s;
        while (ss >> x) {
            ss >> c;
            q.push(x);
        }
        v.push_back(q);
        std::getline(std::cin, s);
        func.push_back(s.substr(23));
        std::getline(std::cin, s);
        div.push_back(std::stoi(s.substr(21)));
        std::getline(std::cin, s);
        int tm = std::stoi(s.substr(29));
        std::getline(std::cin, s);
        int fm = std::stoi(s.substr(30));
        t.push_back(std::make_pair(tm, fm));
        std::getline(std::cin, s);
    }
    int size = v.size();
    std::vector<int> count(size, 0);
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < size; j++) {
            while (!v[j].empty()) {
                int cur = v[j].front();
                v[j].pop();
                cur = monkey(func[j], cur) / 3;
                if (!(cur % div[j])) v[t[j].first].push(cur);
                else v[t[j].second].push(cur);
                count[j]++;
            }
        }
    }
    std::sort(count.begin(), count.end(), std::greater<>());
    std::cout << count[0] * count[1] << std::endl;
}
