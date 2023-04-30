#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <functional>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
vector<int> adj[N];
int ind[N],pre[N];
bool mark[N],vis[N],take[N],pass[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        ind[i]=0;
        adj[i].clear();
        mark[i]=vis[i]=take[i]=pass[i]=0;
    }

    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<int(int,int)> dfs=[&](int u,int fa) {
        debug(u,fa);
        mark[u]=1;
        for(int v:adj[u]) {
            if(v!=fa) {
                if(mark[v]) {
                    if(adj[v].size()>=4) return v;
                }
                else {
                    int res=dfs(v,u);
                    if(res) return res;
                }
            }
        }
        return 0;
    };

    vector<pair<int,int>> ans;
    for(int z=1;z<=n;z++) {
        if(!mark[z]&&adj[z].size()>=4) {
            int i=dfs(z,z);
            debug(z,i);
            if(i) {
                function<bool(int,int)> dfs=[&](int u,int fa) {
                    debug(u,fa);
                    pre[u]=fa;
                    pass[u]=1;
                    for(int v:adj[u]) {
                        if(v!=fa) {
                            if(v==i) {
                                pre[v]=u;
                                return 1;
                            }
                        }
                    }
                    for(int v:adj[u]) {
                        if(v!=fa&&!pass[v]) {
                            if(dfs(v,u)) return 1;
                        }
                    }
                    return 0;
                };
                dfs(i,i);

                int cur=i;
                do {
                    take[cur]=1;
                    ans.emplace_back(cur,pre[cur]);
                    cur=pre[cur];
                } while(cur!=i);

                for(int cnt=0;int v:adj[i]) {
                    if(!take[v]) {
                        ans.emplace_back(i,v);
                        if(++cnt==2) break;
                    }
                }

                cout<<"YES"<<endl;
                cout<<ans.size()<<endl;
                for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}

/*
hack:
1
10 10
1 2
1 3
1 4
1 5
2 6
2 10
7 10
6 7
7 8
7 9
*/