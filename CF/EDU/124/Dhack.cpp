//https://codeforces.com/contest/1651/hacks/790506

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("hack.txt");

    int n = 200'000;
    std::vector<std::pair<int, int>> v;
    int64_t i = 1;
    while (v.size() < n) {
        int64_t first = (i * 172933LL) / 1'000'000,
                second = (i * 172933LL) % 1'000'000;
        if (first > 200'000) {
            break;
        }
        if (1 <= second && second <= 200'000 && 1 <= first) {
            v.emplace_back(first, second);
        }
        ++i;
    }
    out << v.size() << '\n';
    std::mt19937 gen(12345);
    std::shuffle(v.begin(), v.end(), gen);
    for (const auto &p: v) {
        out << p.first << ' ' << p.second << '\n';
    }
    return 0;
}