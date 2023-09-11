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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    LL n,m,k;
    cin>>n>>m>>k;
    vector<LL> tim(n+1);
    auto adj=vector(n+1,vector<int>());
    for(int i=1;i<=n;i++) cin>>tim[i];
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
    }

    auto bf=[&](LL from) {
        vector<int> q;
        vector<int> ind(n+1);
        for(int i=1;i<=n;i++) for(int v:adj[i]) ind[v]++;
        for(int i=1;i<=n;i++) if(!ind[i]) q.emplace_back(i);

        LL cnt=0;
        for(LL i=from;q.size();) {
            int u=0;
            
            for(int x:q) {
                if(tim[x]==i) {
                    u=x;
                    break;
                }
            }

            if(u) {
                for(int v:adj[u]) {
                    if(--ind[v]==0) {
                        q.emplace_back(v);
                    }
                }
                auto it=find(q.begin(),q.end(),u);
                assert(it!=q.end());
                q.erase(it);
            }

            else {
                i++;
                if(i>=k) i=0;
                cnt++;
            }
        }
        return cnt;
    };

    LL ans=numeric_limits<LL>::max();
    for(LL from=0;from<k;from++) {
        ans=min(ans,bf(from));
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}