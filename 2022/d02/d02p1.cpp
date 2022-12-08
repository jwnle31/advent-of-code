#include <iostream>

int main() {
    char x, y;
    int s;
    while (std::cin >> x >> y) s += (y - x - 19) % 3 * 3 + y - 87;
    std::cout << s << std::endl;
}
