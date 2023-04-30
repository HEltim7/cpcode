#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1.5e5+10,M=4e4+10;
int a[N],b[M];
vector<int> posb[M],posa[M];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

    vector<int> num;
    num.push_back(0);
    for(int i=1;i<=m;i++) num.push_back(b[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=m;i++)
        b[i]=--upper_bound(num.begin(),num.end(),b[i])-num.begin();
    for(int i=1;i<=n;i++)
        a[i]=--upper_bound(num.begin(),num.end(),a[i])-num.begin();
    for(int i=1;i<=m;i++) posb[b[i]].push_back(i);
    for(int i=1;i<=n;i++) posa[a[i]].push_back(i);
    debug(num);
    debug(a,1,n);
    debug(b,1,m);

    using BS=bitset<N>;
    BS ng,isok;
    ng.set();
    isok.set();

    for(int i=1;i<num.size();i++) {
        for(int p:posa[i-1]) {
            ng[p]=0;
        }
        for(int p:posb[i]) {
            isok&=ng>>(p-1);
        }
    }

    int ans=0;
    for(int l=1,r=l+m-1;r<=n;l++,r++) ans+=isok[l];
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}