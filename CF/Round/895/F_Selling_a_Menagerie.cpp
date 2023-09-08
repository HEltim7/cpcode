#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
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
    int n;
    cin>>n;
    vector<int> a(n+1),ind(n+1),c(n+1);
    vector<bool> mark(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],ind[a[i]]++;
    for(int i=1;i<=n;i++) cin>>c[i];
    queue<int> q;
    for(int i=1;i<=n;i++) if(!ind[i]) q.emplace(i);

    vector<int> ans;
    while(q.size()) {
        int u=q.front();
        q.pop();
        ans.emplace_back(u);
        mark[u]=1;
        if(!--ind[a[u]]) q.emplace(a[u]);
    }

    auto work=[&](int u) {
        int minn=numeric_limits<int>::max();
        int minu=0;
        while(!mark[u]) {
            mark[u]=1;
            if(c[u]<minn) minn=c[u],minu=a[u];
            u=a[u];
        }
        ans.emplace_back(minu);
        for(u=a[minu];u!=minu;u=a[u]) ans.emplace_back(u);
    };

    for(int i=1;i<=n;i++) if(!mark[i]) work(i);
    for(int u:ans) cout<<u<<' ';
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