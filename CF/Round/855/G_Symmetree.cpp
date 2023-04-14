#include <map>
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];
LL hsh[N];

struct Hasher {
    LL rnd;

    LL operator()(LL x) {
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
    hsh[u]=res;
    return res;
}

bool check(int u,int fa) {
    map<LL,int> cnt;
    int odd=0;
    for(int v:adj[u]) if(v!=fa) {
        if(++cnt[hsh[v]]&1) odd++;
        else odd--;
    }
    if(odd==0) return 1;
    else if(odd>=2) return 0;
    
    LL val=0;
    for(auto [x,y]:cnt) if(y&1) val=x;
    for(int v:adj[u]) if(v!=fa&&hsh[v]==val) return check(v, u);
    return 0;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    if(check(1, 0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}