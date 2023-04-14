#pragma GCC optimize("O2")
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e4+10;
vector<pair<int,int>> adj[N];
bool mark[N];

int sz[N],centroid[2];
void get_centroid(int u,int fa,int tot) {
    int maxx=0;
    sz[u]=1;
    for(auto [v,_]:adj[u]) {
        if(v!=fa&&!mark[v]) {
            get_centroid(v,u,tot);
            sz[u]+=sz[v];
            maxx=max(maxx,sz[v]);
        }
    }
    maxx=max(maxx,tot-sz[u]);
    if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
}

vector<int> num;
void get_len(int u,int fa,int len) {
    num.push_back(len);
    for(auto [v,l]:adj[u]) if(v!=fa&&!mark[v]) get_len(v, u, len+l);
}

int k;
LL countk(int u,int len) {
    LL res=0;
    num.clear();
    get_len(u, 0, len);
    sort(num.begin(),num.end());
    for(int i=-1,j=num.size()-1;j>0;j--) {
        while(i+1<j&&num[i+1]+num[j]<=k) i++;
        res+=min(i+1,j);
    }
    return res;
}

LL solve(int u,int tot) {
    centroid[0]=centroid[1]=0;
    get_centroid(u, 0, tot);
    int root=centroid[0];
    get_centroid(root, 0, tot);
    LL res=countk(root,0);
    mark[root]=1;
    for(auto [v,l]:adj[root]) if(!mark[v]) res-=countk(v,l);
    for(auto [v,_]:adj[root]) if(!mark[v]) res+=solve(v,sz[v]);
    return res;
}

void solve() {
    int n;
    for(;;) {
        cin>>n>>k;
        if(!n&&!k) break;
        for(int i=1;i<=n;i++) mark[i]=0;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++) {
            int u,v,l;
            cin>>u>>v>>l;
            u++,v++;
            adj[u].emplace_back(v,l);
            adj[v].emplace_back(u,l);
        }
        cout<<solve(1,n)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}