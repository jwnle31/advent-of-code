#include <iostream>
#include <string>

int main() {
    std::string s;
    int sum;
    while (std::cin >> s) {
        int size = s.size();
        int a['z' + 1] = { 0 };
        for (int i = 0; i * 2 < size; i++) {
            char c = 0;
            if (a[s[i]] < 0 || s[i] == s[size - i - 1]) c = s[i];
            else if (a[s[size - i - 1]] > 0) c = s[size - i - 1];
            if (c) {
                if (c < 'a') sum += c - 'A' + 27;
                else sum += c - 'a' + 1;
                break;
            }
            a[s[i]] = 1;
            a[s[size - i - 1]] = -1;
        }
    }
    std::cout << sum << std::endl;
}
