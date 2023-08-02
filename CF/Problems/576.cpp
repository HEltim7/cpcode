#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3;
vector<pair<int,int>> ans[N+10];

void solve() {
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        int id=(x-1)/N;
        ans[id].emplace_back(y,i);
    }

    for(int i=0;i<N;i++) {
        if(i&1) sort(ans[i].begin(),ans[i].end());
        else sort(ans[i].begin(),ans[i].end(),greater<>());
        for(auto [_,x]:ans[i]) cout<<x<<' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}