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

using LL=long long;
using ARR=array<int,4>;
constexpr int N=110;
int p[N],col[N];
vector<int> adj[N];

bool check(int u,int c) {
    if(c==2&&adj[u].size()==1) return false;
    for(int v:adj[u]) {
        if(!check(v, c%2+1)) return false;
    }
    return true;
}

void dfs(int u,int c,int mod) {
    col[u]=c;
    for(int v:adj[u]) {
        dfs(v, c%mod+1, mod);
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        cin>>p[i];
        adj[p[i]].emplace_back(i);
    }

    if(adj[1].size()+1==n) {
        cout<<1<<endl;
        for(int i=2;i<=n;i++) cout<<1<<' ';
        cout<<endl;
        cout<<1<<endl;
        return;
    }

    int k=2;
    auto read=[&]() {
        int st;
        cin>>st;
        if(st) exit(0);
        ARR cnt{};
        for(int i=1;i<=k;i++) cin>>cnt[i];
        return cnt;
    };

    for(int v:adj[1]) {
        if(!check(v,1)&&!check(v,2)) {
            k++;
            break;
        }
    }

    if(k==2) {
        for(int v:adj[1]) {
            if(!check(v,1)) dfs(v, 2, 2);
            else dfs(v, 1, 2);
        }
    }
    else for(int v:adj[1]) dfs(v, 1, 3);

    cout<<k<<endl;
    for(int i=2;i<=n;i++) cout<<col[i]<<" \n"[i==n];

    for(;;) {
        ARR in=read();
        if(accumulate(in.begin(),in.end(),0)==1) {
            cout<<max_element(in.begin(),in.end())-in.begin()<<endl;
            continue;
        }

        if(k==2) {
            if(in[1]>1) cout<<2<<endl;
            else if(in[2]>1) cout<<1<<endl;
            else cout<<1<<endl;
        }
        else {
            if(in[3]==0) cout<<1<<endl;
            else if(in[1]==0) cout<<2<<endl;
            else cout<<3<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}