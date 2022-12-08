#include <iostream>
#include <string>

int main() {
    std::string s;
    int sum;
    while (std::cin >> s) {
        int a['z' + 1] = { 0 };
        for (char c : s) if (!a[c]) a[c] = 1;
        std::cin >> s;
        for (char c : s) if (a[c] == 1) a[c] = 2;
        std::cin >> s;
        for (char c : s) {
            if (a[c] == 2) {
                if (c < 'a') sum += c - 'A' + 27;
                else sum += c - 'a' + 1;
                break;
            }
        }
    }
    std::cout << sum << std::endl;
}
