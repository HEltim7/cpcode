#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=2e3+10,M=3e4+10,INF=0x3f3f3f3f;
int e[M],ne[M],f[M],w[M],pre[M],idx;
int h[N],q[N],mf[N],d[N],inq[N];
int S,T,n,m;

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
                mf[t]=min(mf[ver],f[i]);
                pre[t]=i;
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

int EK(){
    int cost=0;
    while(spfa()){
        cost+=d[T]*mf[T];
        for(int i=T;i!=S;i=e[pre[i]^1]){
            f[pre[i]]-=mf[T];
            f[pre[i]^1]+=mf[T];
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    S=0,T=N-1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        add(i,T,in,0);
        add(S,i+n,in,0);
        add(i,i+n,INF,0);
        if(i!=n) add(i+n,i+1,INF,0);
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(b+n,a,INF,c);
    }
    cout<<EK();
    return 0;
}