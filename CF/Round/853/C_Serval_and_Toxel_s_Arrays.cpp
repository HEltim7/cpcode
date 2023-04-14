#include <vector>
#include <iostream>
#include <algorithm>
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
int arr[N];
vector<int> pos[N*2];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n+m;i++) pos[i].clear();
    for(int i=1;i<=n;i++) pos[arr[i]].push_back(0);
    for(int i=1;i<=m;i++) {
        int p,v;
        cin>>p>>v;
        if(arr[p]!=v) {
            pos[arr[p]].push_back(i);
            arr[p]=v;
            pos[arr[p]].push_back(i);
        }
    }

    LL ans=0;
    for(int i=1;i<=n+m;i++) {
        if(pos[i].empty()) continue;
        ans+=1LL*(m+1)*m/2;
        int tot=pos[i][0];
        for(int j=1;j<pos[i].size();j+=2) {
            int idx=pos[i][j];
            int ne=m+1;
            if(j+1<pos[i].size()) ne=pos[i][j+1];
            int len=ne-idx;
            tot+=len;
        }
        debug(i,pos[i],tot);
        ans-=1LL*tot*(tot-1)/2;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}