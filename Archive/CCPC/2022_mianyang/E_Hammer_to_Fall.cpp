#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,mod=998244353;
constexpr LL INF=1e18;
unordered_map<int,int>adj[N];
vector<pair<int,int>> blk,upd;
multiset<LL> st[N];
int a[N],b[N];
bool mark[N];
LL dp[N];

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;
    }
    for(int i=1;i<=q;) {
        cin>>b[i];
        if(b[i]==b[i-1]) q--;
        else i++;
    }

    int len=sqrt(m)*3+1;
    for(int i=1;i<=q;i+=len) blk.emplace_back(i,min(i+len-1,q));
    reverse(blk.begin(),blk.end());
    for(auto [l,r]:blk) {
        for(int i=l;i<=r;i++) {
            int u=b[i];
            if(mark[u]||adj[u].size()<=len) continue;
            mark[u]=1;
            st[u].clear();
            for(auto [v,w]:adj[u]) {
                st[u].emplace(dp[v]+w);
                if(st[u].size()>len) st[u].erase(--st[u].end());
            }
        }
        for(int i=l;i<=r;i++) mark[b[i]]=0;

        for(int i=r;i>=l;i--) {
            upd.clear();
            int u=b[i];
            for(int j=l;j<i;j++) {
                int pre=b[j];
                if(mark[pre]||adj[pre].size()<=len) continue;
                mark[pre]=1;
                auto it=adj[pre].find(u);
                if(it!=adj[pre].end()) {
                    auto itt=st[pre].find(dp[u]+it->second);
                    if(itt!=st[pre].end()) {
                        st[pre].erase(itt);
                        upd.emplace_back(pre,it->second);
                    }
                }
            }
            for(int j=l;j<i;j++) mark[b[j]]=0;

            if(adj[u].size()<=len) {
                dp[u]=INF;
                for(auto [v,w]:adj[u]) dp[u]=min(dp[u],dp[v]+w);
            }
            else dp[u]=*st[u].begin();
            
            for(auto [pre,w]:upd) st[pre].emplace(dp[u]+w);
        }
    }

    LL ans=0;
    for(int i=1;i<=n;i++) ans=(ans+dp[i]%mod*a[i])%mod;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}