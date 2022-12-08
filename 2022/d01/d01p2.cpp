#include <iostream>
#include <string>

int main() {
    std::string s;
    int sum, max1, max2, max3;
    while (std::getline(std::cin, s)) {
        if (s.size()) {
            sum += std::stoi(s);
        } else {
            if (sum > max1) {
                max3 = max2;
                max2 = max1;
                max1 = sum;
            } else if (sum > max2) {
                max3 = max2;
                max2 = sum;
            } else if (sum > max3) {
                max3 = sum;
            }
            sum = 0;
        }
    }
    std::cout << max1 + max2 + max3 << std::endl;
}
