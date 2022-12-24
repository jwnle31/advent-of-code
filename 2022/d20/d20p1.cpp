#include <iostream>
#include <vector>

struct intBool {
    int i;
    bool b;
};

int pos_mod(int m, int n) {
    return (m % n + n) % n;
}

int main() {
    std::vector<intBool> v;
    int x, zidx;
    while (std::cin >> x) v.push_back({x, 0});
    int s = v.size();
    for (int i = 0; i < s; i++) {
        if (v[i].b) continue;
        intBool temp = v[i];
        temp.b = 1;
        v.erase(v.begin() + i);
        int new_pos = pos_mod(i + temp.i, s - 1);
        v.insert(v.begin() + new_pos, temp);
        i--;
    }
    for (int i = 0; i < s; i++) {
        if (!v[i].i) {
            zidx = i;
            break;
        }
    }
    std::cout << v[(zidx + 1000) % s].i + v[(zidx + 2000) % s].i + v[(zidx + 3000) % s].i << std::endl;
}
