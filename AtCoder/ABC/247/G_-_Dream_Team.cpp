#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=310,M=1e5+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],w[M],idx;
int h[N],q[N],pre[N],mf[N];
LL d[N];
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

void EK(int &flow,LL &cost){
    // flow=cost=0;
    while(spfa()){
        flow+=mf[T],cost+=mf[T]*d[T];
        for(int i=T;i!=S;i=e[pre[i]^1]){
            f[pre[i]]-=mf[T];
            f[pre[i]^1]+=mf[T];
        }
    }
}

void restore(){
    for(int i=0;i<idx;i+=2){
        f[i]+=f[i^1];
        f[i^1]=0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(h,-1,sizeof h);
    S=0,T=N-1;
    int s=N-2;
    const int P=150;
    for(int i=1;i<=P;i++)
        add(s,i,1,0),add(i+P,T,1,0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b+P,1,-c);
    }

    LL cost=0;
    vector<LL> ans;
    add(S,s,1,0);
    for(int i=1;i<=n;i++){
        int flow=0;
        EK(flow,cost);
        if(flow==0) break;
        ans.push_back(-cost);
        f[idx-2]++;
        // restore();
    }
    
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<endl;
    return 0;
}