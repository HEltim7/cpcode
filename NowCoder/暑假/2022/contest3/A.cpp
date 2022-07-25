#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using TIII=tuple<int,int,int>;
const int N=1e5+10,M=20;
vector<int> adj[2][N];
int w[2][N];
int fa[2][N][M+1];
int dep[2][N];
int st[N];
int lcaver[2];
int cnts[2][N];
bool inst[N];
vector<int> key;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

void getlca(int u,int p,int z){
    for(auto s:adj[z][u]){
        dep[z][s]=dep[z][u]+1;
        fa[z][s][0]=u;
        for(int i=1;i<=M;i++)
            fa[z][s][i]=fa[z][fa[z][s][i-1]][i-1];
        getlca(s,u,z);
    }
}

int lca(int a,int b,int z){
    if(dep[z][a]<dep[z][b]) swap(a,b);
    for(int k=M;~k;k--)
        if(dep[z][fa[z][a][k]]>=dep[z][b])
            a=fa[z][a][k];
    if(a==b) return a;
    for(int k=M;~k;k--)
        if(fa[z][a][k]!=fa[z][b][k])
            a=fa[z][a][k],b=fa[z][b][k];
    return fa[z][a][0];
}

int get_cnt(int u,int z) {
    if(inst[u]) cnts[z][u]++;
    for(int v:adj[z][u]) cnts[z][u]+=get_cnt(v, z);
    return cnts[z][u];
}

int get_res(int u,int z) {
    if(inst[u]) return u;
    for(int v:adj[z][u]) {
        int t=get_res(v, z);
        if(t) return t;
    }
    return 0;
}

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>st[i],inst[st[i]]=1;
    for(int z=0;z<=1;z++) {
        for(int i=1;i<=n;i++) cin>>w[z][i];
        for(int i=2;i<=n;i++) {
            int p;
            cin>>p;
            adj[z][p].push_back(i);
        }
    }
    dep[0][1]=dep[1][1]=1;
    getlca(1, -1, 0);
    getlca(1, -1, 1);
    for(int z=0;z<=1;z++) {
        lcaver[z]=lca(st[1],st[2],z);
        for(int i=3;i<=k;i++) lcaver[z]=lca(lcaver[z],st[i],z);
        debug(lcaver[z]);
    }
    for(int z=0;z<=1;z++) {
        int u=lcaver[z];
        get_cnt(u,z);
        int trs=0;
        int trs2=0;
        for(int v:adj[z][u]) {
            if(cnts[z][v]) trs++;
            if(cnts[z][v]>=2) trs2++;
        }
        if(inst[u]) {
            if(trs<=1) key.push_back(u);
        }
        else if(trs<3&&trs2<2) {
            for(int v:adj[z][u]) {
                if(cnts[z][v]==1) 
                    key.push_back(get_res(v, z));
            }
        }
        debug(key);
    }
    sort(key.begin(),key.end());
    key.erase(unique(key.begin(),key.end()),key.end());
    debug(key);
    assert(key.size()<=4);
    int ans=0;
    for(auto x:key) {
        assert(inst[x]);
        int a=-1,b=-1;
        for(int i=1;i<=k;i++) if(st[i]!=x) {
            if(a==-1) a=st[i];
            else a=lca(a,st[i],0);
            if(b==-1) b=st[i];
            else b=lca(b,st[i],1);
        }
        if(w[0][a]>w[1][b]) ans++;
    }
    if(w[0][lcaver[0]]>w[1][lcaver[1]]) ans+=k-key.size(); 
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}