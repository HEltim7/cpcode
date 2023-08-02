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
constexpr int N=1e3+10;
int edg[N][N];
LL cnt[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            edg[i][j]=cnt[i][j]=0;
    }
    
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        edg[u][v]++;
        edg[v][u]++;
    }

    for(int i=1;i<=n;i++) {
        LL tot=0;
        for(int j=1;j<=n;j++) tot+=edg[i][j];
        for(int j=1;j<=n;j++) {
            if(edg[i][j]) {
                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}