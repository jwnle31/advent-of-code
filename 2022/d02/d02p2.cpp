#include <iostream>

int main() {
    char x, y;
    int s;
    while (std::cin >> x >> y) s += (x + y - 151) % 3 + 3 * y - 263;
    std::cout << s << std::endl;
}
