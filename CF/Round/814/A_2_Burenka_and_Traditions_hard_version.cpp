#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=1<<(__lg(N)+1);
int pre[N],dp[N];

void solve() {
    int n;
    cin>>n;
    map<int,int> pos;
    for(int i=1;i<=n;i++) cin>>pre[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]^pre[i];
    pos.emplace(0,0);
    for(int i=1;i<=n;i++) {
        dp[i]=dp[i-1]+1;
        auto it=pos.find(pre[i]);
        if(it!=pos.end()) {
            int idx=it->second;
            int len=i-idx;
            dp[i]=min(dp[i],dp[idx]+len-1);
        }
        pos[pre[i]]=i;
    }
    cout<<dp[n]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}