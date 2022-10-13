#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e4+20,M=1e5+10,INF=0x3f3f3f3f,LARGE=1e4;
using PII=pair<int,int>;
int ne[M],e[M],f[M],w[M],idx;
int h[N],q[N],d[N],pre[N],mf[N];
int n,m,S,T;
bool inq[N];
bool nocar[N];
int leap[N];

void add(int a,int b,int c,int d){
    e[idx]=b,f[idx]=c,w[idx]=d,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,w[idx]=-d,ne[idx]=h[b],h[b]=idx++;
}

bool spfa(){
    memset(d,0x3f,sizeof(int)*T);
    memset(mf,0,sizeof(int)*T);
    int hh=0,tt=1;
    q[0]=S,d[S]=0,mf[S]=INF;
    while(hh!=tt){
        int ver=q[hh++];
        if(hh==N) hh=0;
        inq[ver]=0;

        for(int i=h[ver];~i;i=ne[i]){
            int t=e[i];
            if(f[i]&&d[t]>d[ver]+w[i]){
                d[t]=d[ver]+w[i];
                pre[t]=i;
                mf[t]=min(mf[ver],f[i]);
                if(!inq[t]){
                    q[tt++]=t;
                    if(tt==N) tt=0;
                    inq[t]=1;
                }
            }
        }
    }
    return mf[T]>0;
}

void EK(int &flow,int &cost) {
    flow=cost=0;
    while(spfa()){
        flow+=mf[T],cost+=mf[T]*d[T];
        for(int i=T;i!=S;i=e[pre[i]^1]){
            f[pre[i]]-=mf[T];
            f[pre[i]^1]+=mf[T];
        }
    }
}

void solve() {
    int n,m,ff,k;
    cin>>n>>m;
    S=0,T=n+10;
    memset(h, -1, sizeof(int)*T);
    memset(nocar, 0, sizeof(int)*T);
    idx=0;

    for(int i=1,u,v;i<=m;i++) {
        cin>>u>>v;
        add(u, v, INF, LARGE);
        add(v, u, INF, LARGE);
    }
    cin>>ff;
    for(int i=1,u;i<=ff;i++) {
        cin>>u;
        add(u, T, 1, 0);
    }
    cin>>k;
    vector<int> edge;
    for(int i=1,u;i<=k;i++) {
        cin>>u;
        nocar[u]=1;
        leap[u]=n+i;
        add(u, leap[u], 1, -1);
        edge.push_back(idx-1);
    }
    for(int i=0,t=idx;i<t;i+=2) {
        if(nocar[e[i^1]]) {
            add(leap[e[i^1]], e[i], f[i], w[i]-1);
        }
    }
    
    add(S, 1, ff, 0);
    int flow,cost;
    EK(flow, cost);

    int ans=0;
    for(auto x:edge) ans+=f[x];
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}