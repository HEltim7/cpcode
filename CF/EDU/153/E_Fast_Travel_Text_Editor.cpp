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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int A=26*26,N=5e4+A+10;
int pre[N][A],suf[N][A];
int ans[A][N];
bool mark[N];
vector<int> adj[N];

void bfs(int id) {
    memset(mark, 0, sizeof mark);
    queue<pair<int,int>> q;
    q.emplace(0,id);
    mark[id]=1;
    while(q.size()) {
        auto [d,u]=q.front();
        ans[id][u]=d;
        q.pop();
        for(int v:adj[u]) {
            if(!mark[v]) {
                debug(v-A,d+1);
                mark[v]=1;
                q.emplace(d+1,v);
            }
        }
    }
};

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;

    auto get=[&](int i) {
        int x=s[i]-'a';
        int y=s[i+1]-'a';
        int id=x*26+y;
        return id;
    };

    for(int i=1;i<n;i++) {
        int id=get(i);
        adj[i+A].emplace_back(id);
        adj[id].emplace_back(i+A);
        if(i>1) {
            adj[i+A].emplace_back(i-1+A);
        }
        if(i+1<n) {
            adj[i+A].emplace_back(i+1+A);
        }
    }
    for(int i=0;i<A;i++) if(adj[i].size()) bfs(i);

    for(int i=1;i<n;i++) {
        memcpy(pre[i], pre[i-1], sizeof pre[i]);
        pre[i][get(i)]=i;
    }
    for(int i=n-1;i>=1;i--) {
        memcpy(suf[i], suf[i+1], sizeof suf[i]);
        suf[i][get(i)]=i;
    }

    int q;
    cin>>q;
    while(q--) {
        int f,t;
        cin>>f>>t;
        int res=abs(f-t);
        for(int i=0;i<A;i++) {
            if(pre[f][i]) {
                res=min(res,ans[i][t+A]+f-pre[f][i]);
            }
            if(suf[f][i])
                res=min(res,ans[i][t+A]+suf[f][i]-f);
        }
        cout<<res<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}