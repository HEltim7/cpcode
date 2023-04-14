#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using Balls=array<int,10>;
constexpr int N=1e5+10,M=10;
Balls state[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<M;i++) state[0][i]=i;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        state[i]=state[i-1];
        swap(state[i][a],state[i][b]);
    }
    while(m--) {
        int l,r;
        cin>>l>>r;
        Balls id;
        for(int i=0;i<M;i++) id[state[l-1][i]]=i;
        for(int i=0;i<M;i++) cout<<id[state[r][i]]<<" \n"[i==M-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}