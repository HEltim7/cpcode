#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e2+10;
int dis[N][N];
int fa[N];
vector<tuple<int,int,int>> edge;
vector<pair<int,int>> ans;

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void kruskal(int n) {
    sort(edge.begin(),edge.end());
    int cnt=0;
    for(auto [d,u,v]:edge) {
        int x=findfa(u),y=findfa(v);
        if(x==y) continue;
        fa[x]=y;
        ans.emplace_back(u,v);
        if(++cnt==n-1) break;
    }
    sort(ans.begin(),ans.end());
}

void solve() {
    int n;
    cin>>n;
    edge.clear(),ans.clear();
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            cin>>dis[i][j];
            if(i<j) edge.emplace_back(dis[i][j],i,j);
        }
    kruskal(n);
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans) cout<<u<<' '<<v<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}