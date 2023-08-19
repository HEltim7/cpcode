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
#include <unordered_set>
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
    int n,m;
    cin>>n>>m;
    auto grid=vector(n,string{});
    queue<int> rq,cq;
    auto rcnt=vector(n,vector(1<<7,0));
    auto ccnt=vector(m,vector(1<<7,0));
    auto ridx=vector(n,unordered_set<int>());
    auto cidx=vector(m,unordered_set<int>());
    auto rdif=vector(n,0);
    auto cdif=vector(m,0);
    int rans=0,cans=0;

    for(int i=0;i<n;i++) cin>>grid[i];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ridx[i].emplace(j);
            if(++rcnt[i][grid[i][j]]==1) rdif[i]++;
        }
        if(rdif[i]==1) rq.emplace(i);
    }
    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            cidx[j].emplace(i);
            if(++ccnt[j][grid[i][j]]==1) cdif[j]++;
        }
        if(cdif[j]==1) cq.emplace(j);
    }

    while(rq.size()||cq.size()) {
        if(rq.size()) {
            int i=rq.front();
            debug(i);
            rq.pop();
            rans++;
            for(int j:ridx[i]) {
                cidx[j].erase(i);
                if(--ccnt[j][grid[i][j]]==0)
                    if(--cdif[j]==1&&cidx[j].size()>=2) cq.emplace(j);
            }
        }
        if(cq.size()) {
            int j=cq.front();
            debug(j);
            cq.pop();
            cans++;
            for(int i:cidx[j]) {
                ridx[i].erase(j);
                if(--rcnt[i][grid[i][j]]==0)
                    if(--rdif[i]==1&&ridx[i].size()>=2) rq.emplace(i);
            }
        }
    }

    int ans=(n-rans)*(m-cans);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}