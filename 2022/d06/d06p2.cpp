#include <iostream>
#include <string>
#include <sstream>

int main() {
    char c;
    int a[26] = { 0 };
    int left = 1;
    for (int i = 1; ; i++) {
        if (!(std::cin >> c)) break;
        if (a[c - 'a'] + 1 > left) left = a[c - 'a'] + 1;
        a[c - 'a'] = i;
        if (i - left == 13) {
            std::cout << i << std::endl;
            break;
        }
    }
}
