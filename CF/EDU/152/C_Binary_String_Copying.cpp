#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=2e5+10;
int r1[N],l0[N];

void solve() {
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s=" "+s;

    for(int i=n,idx=-1;i>=1;i--) {
        if(s[i]=='1') idx=i,r1[i]=i;
        else r1[i]=idx;
    }

    for(int i=1,idx=-1;i<=n;i++) {
        if(s[i]=='0') idx=i,l0[i]=i;
        else l0[i]=idx;
    }

    vector<pair<int,int>> vec;
    for(int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        l=r1[l];
        r=l0[r];
        if(l==-1||r==-1||l>r) vec.emplace_back(-1,-1);
        else vec.emplace_back(l,r);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    debug(vec);
    cout<<vec.size()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}