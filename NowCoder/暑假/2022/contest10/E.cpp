#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=810,M=1e6+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],w[M],idx;
int h[N],q[N],d[N],pre[N],mf[N];
int n,m,S,T,cnt=0;
bool inq[N];
int sd,ed;

void add(int a,int b,int c,int d){
    e[idx]=b,f[idx]=c,w[idx]=d,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,w[idx]=-d,ne[idx]=h[b],h[b]=idx++;
}

bool spfa(){
    memset(d,0x3f,sizeof (int)*(cnt));
    memset(mf,0,sizeof (int)*(cnt));
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

void EK(int &flow,int &cost){
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
    int n,m;
    cin>>n>>m;
    cnt=n+m+5;
    memset(h, -1, sizeof(int)*(cnt));
    S=0,T=cnt-1;
    for(int i=1;i<=n;i++) add(S,i,1,0);

    sd=idx;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            if(in=='1') add(i,j+n,1,0);
        }
    ed=idx;

    for(int i=1;i<=m;i++) 
        for(int j=1;j<=n;j++) 
            add(n+i,T,1,-j);

    int flow=0,cost=0;
    EK(flow,cost);

    if(flow<n) cout<<"-1";
    else {
        for(int i=sd;i<ed;i+=2) 
            if(!f[i]) cout<<e[i]-n<<' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}