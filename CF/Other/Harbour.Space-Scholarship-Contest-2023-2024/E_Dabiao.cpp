#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
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
constexpr int N=(1<<7)+1;
int ans[N][N];
int mxa[N][N];
int mxb[N][N];
bool marka[N][N][N];
bool markb[N][N][N];
bool vis[N][N];
vector<pair<int,int>> seg[N];
using BS=bitset<__lg(N)+1>;

void solve() {
    using T=tuple<int,int,int>;
    priority_queue<T,vector<T>,greater<>> q;
    auto check=[&](int x,bool mark[]) {
        int eq=!mark[x];
        int ge=0,le=0;
        for(int i=x+1;i<N;i++) ge|=!mark[i];
        for(int i=0;i<x;i++) le|=!mark[i];
        return eq+ge+le<=1;
    };
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                if((i|k)!=(i|j)) {
                    marka[i][j][k]=true;
                }
                if((k|j)!=(i|j)) {
                    markb[i][j][k]=true;
                }
            }
            if(check(i,marka[i][j])) {
                q.emplace(1,i,j);
            }
            else if(check(j,markb[i][j])) {
                q.emplace(2,i,j);
            }
        }
    }

    while(q.size()) {
        auto [r,a,b]=q.top();
        q.pop();
        if(vis[a][b]) continue;
        vis[a][b]=1;
        ans[a][b]=r;
        // debug(a,b,ans[a][b]);
        
        for(int bb=0;bb<N;bb++) {
            if(!marka[a][bb][b]&&(a|b)==(a|bb)) {
                marka[a][bb][b]=true;
                mxa[a][bb]=max(mxa[a][bb],r+1);
                if(check(a,marka[a][bb])) {
                    q.emplace(mxa[a][bb],a,bb);
                }
            }
        }
        for(int aa=0;aa<N;aa++) {
            if(!markb[aa][b][a]&&(a|b)==(aa|b)) {
                markb[aa][b][a]=true;
                mxb[aa][b]=max(mxb[aa][b],r+1);
                if(check(b,markb[aa][b])) {
                    q.emplace(mxb[aa][b],aa,b);
                }
            }
        }
    }
    
    debug(debug::MAXSIZE=1000);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) seg[ans[i][j]].emplace_back(i,j);
    for(int i=0;i<N;i++) {
        if(seg[i].size()) {
            debug(i);
            int maxcnt=0,mincnt=1000;
            for(auto [a,b]:seg[i]) {
                if(a==b) continue;
                auto A=BS(a),B=BS(b),C=BS(a|b),D=BS(a&b),E=BS(a^b);
                debug(A,B,C,a>b);
                int i=E._Find_first();
                int cnt=-1;
                while(i<D.size()) i=D._Find_next(i),cnt++;
                maxcnt=max(maxcnt,cnt);
                mincnt=min(mincnt,cnt);
            }
            debug(maxcnt,mincnt);
            debug();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}