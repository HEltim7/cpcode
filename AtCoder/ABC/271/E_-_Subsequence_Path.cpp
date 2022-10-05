#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
constexpr int N=2e5+10;
constexpr LL INF=0x3f3f3f3f3f3f3f3f;
LL dis[N];
TIII edge[N];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    memset(dis, 0x3f, sizeof(LL)*(n+1));
    dis[1]=0;
    for(int i=1;i<=m;i++) {
        int u,v,d;
        cin>>u>>v>>d;
        edge[i]={u,v,d};
    }
        
    for(int i=1;i<=k;i++) {
        int id;
        cin>>id;
        auto [u,v,d]=edge[id];
        dis[v]=min(dis[v],dis[u]+d);
    }

    if(dis[n]==INF) cout<<"-1"<<endl;
    else cout<<dis[n]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}