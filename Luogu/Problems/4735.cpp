#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=6e5+10;

struct PersistentTrie {

    constexpr static int MAX_SIZE=N*30;
    constexpr static int ALPHABET=2;
    
    struct Node {
        int ch[ALPHABET];
        int sum;
    } tr[MAX_SIZE];

    template<typename T> void insert(T &s) {
        for(auto x:s) {
            
        }
    }
};

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}