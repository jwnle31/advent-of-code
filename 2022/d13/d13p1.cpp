#include <iostream>
#include <sstream>
#include <vector>

struct Packet {
    int signal = -1;
    std::vector<Packet> v;
};

std::vector<Packet> build_packet(std::string s) {
    std::vector<Packet> packet;
    if (s == "[]") return packet;
    char c;
    int x;
    s = s.substr(1, s.size() - 1);
    std::stringstream ss(s);
    while (true) {
        c = ss.peek();
        if (!ss) {
            return packet;
        } else if (isdigit(c)) {
            ss >> x;
            packet.push_back({x, {}});
        } else if (c == '[') {
            s = "";
            int cnt = 0;
            while (ss >> c) {
                s += c;
                if (c == '[') cnt++;
                else if (c == ']') cnt--;
                if (!cnt) {
                    packet.push_back({-1, build_packet(s)});
                    break;
                }
            }
        } else  {
            ss >> c;
        }
    }
}

int compare_packet (std::vector<Packet> v1, std::vector<Packet> v2) {
    int s1 = v1.size(), s2 = v2.size(), size = std::min(s1, s2);
    for (int i = 0; i < size; i++) {
        int v1s = v1[i].signal, v2s = v2[i].signal;
        if (v1s >= 0 && v2s >= 0) {
            if (v1s < v2s) return -1;
            else if (v1s > v2s) return 1;
        } else {
            auto v1v = v1[i].v, v2v = v2[i].v;
            if (v1s >= 0 && v2s < 0) v1v = {v1[i]};
            else if (v1s < 0 && v2s >= 0) v2v = {v2[i]};
            int comp = compare_packet(v1v, v2v);
            if (comp) return comp;
        }
    }
    if (s1 == s2) return 0;
    else if (size == s1) return -1;
    else return 1;
}

int main() {
    std::string s;
    int idx = 1, sum = 0;
    while (std::cin >> s) {
        std::vector<Packet> v1 = build_packet(s);
        std::cin >> s;
        std::vector<Packet> v2 = build_packet(s);
        if (compare_packet(v1, v2) < 0) sum += idx;
        idx++;
    }
    std::cout << sum << std::endl;
}
