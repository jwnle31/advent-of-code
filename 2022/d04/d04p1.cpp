#include <iostream>

int main() {
    int a[4];
    int count;
    char c;
    while (std::cin >> a[0] >> c >> a[1] >> c >> a[2] >> c >> a[3]) {
        if (a[0] <= a[2] && a[3] <= a[1] || a[2] <= a[0] && a[1] <= a[3]) count++;
    }
    std::cout << count << std::endl;
}
