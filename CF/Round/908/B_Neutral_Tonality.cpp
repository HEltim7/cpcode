#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> num;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i],num.emplace_back(a[i]);
    for(int i=0;i<m;i++) cin>>b[i];
    sort(b.begin(),b.end(),greater<>());

    num.emplace_back(0);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    auto get=[&](int x) {
        return upper_bound(num.begin(),num.end(),x)-num.begin()-1;
    };
    
    vector<vector<int>> vec(n+1);
    vector<int> pre(n+1);
    for(int i=n-1;i>=0;i--) pre[get(a[i])]=i;
    for(int i=0;i<m;i++) {
        int t=get(b[i]);
        if(t) vec[pre[t]].emplace_back(b[i]);
    }

    for(int i=0;i<n;i++) {
        for(int x:vec[i]) cout<<x<<' ';
        cout<<a[i]<<' ';
    }
    for(int i=0;i<m;i++) if(b[i]<num[1]) cout<<b[i]<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}