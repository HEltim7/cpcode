#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=110,M=1e5+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],w[M],idx;
int h[N],q[N],d[N],pre[N],mf[N];
int n,m,S,T;
bool inq[N];

inline void add(int a,int b,int c,int d){
    e[idx]=b,f[idx]=c,w[idx]=d,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,w[idx]=-d,ne[idx]=h[b],h[b]=idx++;
}

bool spfa(){
    memset(d,0x3f,sizeof d);
    memset(mf,0,sizeof mf);
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

#define __LOCAL
#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(h,-1,sizeof h);
    S=0,T=N-1;
    int s=N-3,t=N-2;
    add(t,s,INF,0);
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int in;
            cin>>in;
            ans+=in;
            add(i,j+n,1,-in);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int in;
            cin>>in;
            add(i,j+n,1,in);
        }
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        add(s,i,b-a,0);
        add(S,i,m-b,0);
        add(s,T,m-b,0);
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(i+n,t,b-a,0);
        add(S,t,n-b,0);
        add(i+n,T,n-b,0);
    }
    int flow,cost;
    EK(flow,cost);
    debug(flow,cost);
    cout<<ans+cost<<endl;
    return 0;
}