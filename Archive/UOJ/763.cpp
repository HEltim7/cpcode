#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
vector<int> adj[N];
vector<LL> hsh;

struct Hasher {
    LL rnd;

    LL operator ()(LL x) {
        x^=rnd;
        x^=x<<13;
        x^=x>>7;
        x^=x<<13;
        x^=rnd;
        return x;
    }

    Hasher() {
        mt19937 gen(random_device{}());
        rnd=gen();
    }
} f;

LL dfs(int u,int fa) {
    LL res=1;
    for(int v:adj[u]) if(v!=fa) res+=f(dfs(v,u));
    hsh.push_back(res);
    return res;
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    sort(hsh.begin(),hsh.end());
    hsh.erase(unique(hsh.begin(),hsh.end()),hsh.end());
    cout<<hsh.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}