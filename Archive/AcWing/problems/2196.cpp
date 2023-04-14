#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=2e3+10,M=6e5,P=1e5+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],w[M],idx;
int h[N],q[N],d[N],pre[N],mf[N];
int n,k,S,T;
bool inq[N];
PII seg[N];
vector<int> line[P];

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    memset(h,-1,sizeof h);
    S=0,T=N-1;
    int SS=N-2;
    add(S,SS,n,0);
    add(SS,T,INF,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        add(i+n,i+2*n,1,a-b);
        seg[i]={a,b};
        line[a].emplace_back(i);
        line[b].emplace_back(i);
    }
    int idx1=0,idx2=3*n;
    set<int> st;
    for(int i=1;i<P;i++){
        vector<int> tmp;
        for(int x:line[i]){
            if(seg[x].first==i){
                //加入新的点
                tmp.push_back(x);
            }
            else st.erase(x);
        }
        if(tmp.size()){
            add(++idx2,T,k,0); 
            for(int x:tmp) add(x+2*n,idx2,1,0);
            if(k>st.size()){
                add(SS,++idx1,tmp.size(),0);
                for(int x:tmp) add(idx1,x+n,1,0);
            }
            if(st.size()){
                for(int x:st) for(int y:tmp) 
                    add(x+n,y+2*n,1,seg[y].first-seg[y].second);
            }
            for(int x:tmp) st.insert(x);
        }
    }
    int flow,cost;
    EK(flow,cost);
    cout<<flow<<' '<<-cost<<endl;
    return 0;
}