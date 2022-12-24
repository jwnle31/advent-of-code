#include <iostream>
#include <vector>
#define ll long long

struct llInt {
    ll i;
    int idx;
};

int pos_mod(ll m, int n) {
    return (m % n + n) % n;
}

int main() {
    std::vector<llInt> v;
    ll x;
    int count = 0, zidx;
    while (std::cin >> x) v.push_back({x * 811589153, count++});
    int s = v.size();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < s; j++) {
            int idx;
            for (int k = 0; k < s; k++) {
                if (v[k].idx == j) {
                    idx = k;
                    break;
                }
            }
            llInt temp = v[idx];
            v.erase(v.begin() + idx);
            int new_pos = pos_mod(idx + temp.i, s - 1);
            v.insert(v.begin() + new_pos, temp);
        }
    }
    for (int i = 0; i < s; i++) {
        if (!v[i].i) {
            zidx = i;
            break;
        }
    }
    std::cout << v[(zidx + 1000) % s].i + v[(zidx + 2000) % s].i + v[(zidx + 3000) % s].i << std::endl;
}
