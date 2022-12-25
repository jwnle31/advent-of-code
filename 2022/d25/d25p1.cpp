#include <algorithm>
#include <iostream>
#include <unordered_map>
#define ll long long

int main() {
    ll sum = 0, p5;
    std::string s;
    std::unordered_map<char, int> ci = {{0, '0'}, {'1', 1}, {'2', 2}, {'-', -1}, {'=', -2}};
    while (std::cin >> s) {
        p5 = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            sum += p5 * ci[s[i]];
            p5 *= 5;
        }
    }
    s = "";
    ll carry = 0, r, d;
    std::unordered_map<int, char> ic = {{0, '0'}, {1, '1'}, {2, '2'}, {3, '='}, {4, '-'}};
    while (sum || carry) {
        r = (sum + carry) % 5;
        d = (sum + carry) / 5;
        s.push_back(ic[r]);
        carry = (r >= 3) ? 1 : 0;
        sum = d;
    }
    reverse(s.begin(), s.end());
    std::cout << s << std::endl;
}
