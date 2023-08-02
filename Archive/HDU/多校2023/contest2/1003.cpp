#include<iostream>
#include<cmath>
#include<cstring>
#include<cassert>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<vector>
#include<set>
#include<unordered_set>
#include<bitset>
#include<climits>
#include<numeric>
#include<functional>
#include<iomanip>

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define ALL(a) a.begin(),a.end()
using namespace std;
using ll=long long;
struct Tarjan {
    int n,dn,rt;
    vector<vector<int>> g;
    vector<vector<int>> vcc;
    vector<int> dfn,low,cut;
    stack<int> st;
    Tarjan(int n):n(n),dn(0),g(n),dfn(n),low(n),cut(n) {}
    void addEdge(int u,int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    void tarjan(int u) {
        dfn[u]=low[u]=++dn;
        st.push(u);
        int chd=0;
        for(int v:g[u]) {
            if(!dfn[v]) {
                tarjan(v);
                low[u]=min(low[u], low[v]);
                if(dfn[u]<=low[v]) {
                    if(u!=rt||++chd>1) cut[u]=1;// 割点
                    vcc.push_back({u});
                    for (int x=-1; x!=v; st.pop())
                        vcc.back().push_back(x=st.top());
                }
            }else {// 返祖边
                // 求vcc判不判回头边无所谓
                low[u]=min(low[u], dfn[v]);
            }
        }
        if(u==rt&&chd==0)// 孤点
            vcc.push_back({u});
    }
    void converge() {
        for(rt=0; rt<n; ++rt) 
            if(!dfn[rt]) tarjan(rt);
    }
    // 圆方树/森林
    auto newTree() {
        vector<vector<int>> tr(n+vcc.size());
        for(int i=0; i<vcc.size(); ++i)
            for(int x:vcc[i]) {
                tr[n+i].push_back(x);// 方点向圆点连边
                tr[x].push_back(n+i);
            }
        return tr;
    }
};
constexpr int N=2e5+10,INF=N*2;
int dp[N*2][2],max1[N*2],max2[N*2];
bool key[N*2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) {
        int n,m,k;
        cin>>n>>m>>k;
        Tarjan tar(n);
        for(int i=0; i<m; ++i) {
            int u,v;
            cin>>u>>v;
            --u,--v;
            tar.addEdge(u,v);
        }
        tar.converge();
        auto&& adj=tar.newTree();

        for(int i=1;i<=k;i++) {
            int in;
            cin>>in;
            key[in-1]=1;
        }

        auto upd=[&](int &max1,int &max2,int v) {
            if(v>=max1) {
                max2=max1;
                max1=v;
            }
            else if(v>=max2) {
                max2=v;
            }
        };

        function<void(int,int)> dfs1=[&](int u,int fa) {
            if(key[u]) dp[u][0]++;
            for(int v:adj[u]) {
                if(v!=fa) {
                    dfs1(v, u);
                    if(key[u]) {
                        dp[u][0]+=min(dp[v][0],dp[v][1]);
                        dp[u][1]+=dp[v][0];
                    }
                    else {
                        dp[u][0]+=dp[v][0];
                        dp[u][1]+=dp[v][0];
                        upd(max1[u], max2[u], dp[v][0]-dp[v][1]);
                    }
                }
            }
            if(!key[u]) dp[u][1]-=max1[u];
        };
        dfs1(0,-1);
        
        int ans=min(dp[0][0],dp[0][1]);
        debug(ans);
        function<void(int,int)> dfs2=[&](int u,int fa) {
            if(fa!=-1) {
                int cur=dp[u][0]-dp[u][1];
                int maxx=max1[fa];
                if(cur==maxx) maxx=max2[fa];

                int ans0,ans1;
                if(key[fa]) {
                    ans0=dp[fa][1]-dp[u][0];
                    ans1=dp[fa][0]-min(dp[u][0],dp[u][1]);
                }
                else {
                    ans0=dp[fa][0]-dp[u][0];
                    ans1=dp[fa][1]-dp[u][0]+max1[fa]-maxx;
                }

                if(key[u]) {
                    dp[u][0]+=min(ans0,ans1);
                    dp[u][1]+=ans0;
                }
                else {
                    dp[u][0]+=ans0;
                    dp[u][1]+=ans0+max1[u]-max(max1[u],ans0-ans1);
                    upd(max1[u], max2[u], ans0-ans1);
                }
                ans=min({ans,dp[u][0],dp[u][1]});
            }
            for(int v:adj[u]) {
                if(v!=fa) {
                    dfs2(v, u);
                }
            }
        };
        dfs2(0,-1);

        cout<<ans<<endl;
    }
    return 0;
}
/*




*/