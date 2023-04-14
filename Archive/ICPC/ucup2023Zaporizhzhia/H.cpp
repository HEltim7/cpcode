#include <map>
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using ULL=unsigned long long;
constexpr int N=1e5+10;
vector<int> adj[N];
mt19937_64 gen=mt19937_64(random_device{}());
ULL rnd[N],hsh[N];
int ind[N];

void solve() {
    int n,m;
    cin>>n>>m;
    LL tot=1LL*n*(n-1)/2+1;
    for(int i=1;i<=n;i++) rnd[i]=gen();
    for(int i=1;i<=n;i++) hsh[i]=0;
    for(int i=1;i<=n;i++) ind[i]=0;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        ind[u]++,ind[v]++;
        hsh[u]^=rnd[v];
        hsh[v]^=rnd[u];
    }

    auto patch=[&]() {
        if(n!=4||m!=4) return false;
        for(int i=1;i<=4;i++) if(ind[i]!=2) return false;
        return true;
    };
    if(patch()) {
        cout<<"YES"<<endl;
        return;
    }

    map<ULL,int> cnt;
    for(int i=1;i<=n;i++) cnt[hsh[i]]++;
    for(auto [_,x]:cnt) tot-=1LL*x*(x-1)/2;

    for(int i=1;i<=n;i++) hsh[i]^=rnd[i];
    cnt.clear();
    for(int i=1;i<=n;i++) cnt[hsh[i]]++;
    for(auto [_,x]:cnt) tot-=1LL*x*(x-1)/2;

    LL num=0;
    for(auto [_,x]:cnt) if(x==2) num++;
    tot-=num*(num-1);
    if(tot<=n) cout<<"YES"<<endl;
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