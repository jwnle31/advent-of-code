#include <iostream>
#include <string>

int main() {
    std::string s;
    int sum, max;
    while (std::getline(std::cin, s)) {
        if (s.size()) {
            sum += std::stoi(s);
        } else {
            if (sum > max) max = sum;
            sum = 0;
        }
    }
    std::cout << max << std::endl;
}
