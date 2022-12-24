#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define ll long long

struct ssc {
    std::string s1, s2;
    char c;
};

int main() {
    std::unordered_map<std::string, ll> um;
    std::unordered_set<std::string> us, humn;
    std::unordered_map<std::string, ssc> u;
    std::string s;
    humn.insert("humn");
    while (std::getline(std::cin, s)) {
        if (s.length() == 17 && !isdigit(s[11])) us.insert(s);
        else um[s.substr(0, 4)] = stoll(s.substr(6));
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
                if (humn.find(m1) != humn.end() || humn.find(m2) != humn.end()) humn.insert(m);
                u[m] = {m1, m2, (*it)[11]};
                it = us.erase(it);
            } else {
                ++it;
            }
        }
    }
    ll n;
    bool flag = humn.find(u["root"].s1) != humn.end();
    s = flag ? u["root"].s1 : u["root"].s2;
    n = flag ? um[u["root"].s2] : um[u["root"].s1];
    while (s != "humn") {
        auto st = u[s];
        flag = humn.find(st.s1) != humn.end();
        if (st.c == '+') n = flag ?  n - um[st.s2] : n - um[st.s1];
        else if (st.c == '-') n = flag ? n + um[st.s2] : um[st.s1] - n;
        else if (st.c == '*') n = flag ? n / um[st.s2] : n / um[st.s1];
        else  n = flag ? n * um[st.s2] : um[st.s1] / n;
        s = flag ? st.s1 : st.s2;
    }
    std::cout << n << std::endl;
}
