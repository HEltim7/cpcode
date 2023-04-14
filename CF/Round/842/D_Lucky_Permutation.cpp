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
bool mark[N];
vector<int> stk;

void dfs(int u) {
    if(!mark[u]) {
        mark[u]=1;
        stk.push_back(u);
        dfs(arr[u]);
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) mark[i]=0;

    int ans=0;
    bool flag=0;
    for(int i=1;i<=n;i++) {
        stk.clear();
        if(!mark[i]) dfs(i);
        if(stk.size()>=2) {
            sort(stk.begin(),stk.end());
            for(int i=1;i<stk.size();i++) {
                if(stk[i]-stk[i-1]==1) flag=1;
            }
            ans+=stk.size()-1;
            debug(i,stk);
        }
    }

    debug(ans,flag);
    if(ans==0) cout<<1<<endl;
    else if(flag) cout<<ans-1<<endl;
    else cout<<ans+1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}