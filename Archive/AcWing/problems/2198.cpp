#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=3e3+10,M=1e5+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],w[M],idx;
int h[N],q[N],d[N],pre[N],mf[N];
int k,n,m,S,T;
bool inq[N];
vector<int> ans;

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

inline int get(int row,int col){
    return (row-1)*m+col;
}

inline bool check(int row,int col){
    return row>=1&&row<=n&&col>=1&&col<=m;
}

void dfs(int root){
    if(root<=n*m){
        ans.push_back(root);
        dfs(root+n*m);
        return;
    }
    for(int i=h[root];~i;i=ne[i]){
        int ver=e[i];
        if(ver==root-n*m||!f[i^1]) continue;
        f[i^1]-=1;
        dfs(ver);
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>k>>m>>n;
    memset(h,-1,sizeof h);
    S=0,T=N-1;
    add(S,get(1,1),k,0);
    add(get(n,m)+n*m,T,INF,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int in;
            cin>>in;
            if(in==0||in==2){
                add(get(i,j),get(i,j)+n*m,INF,0);
                if(check(i+1,j)) add(get(i,j)+n*m,get(i+1,j),INF,0);
                if(check(i,j+1)) add(get(i,j)+n*m,get(i,j+1),INF,0);
                if(in) add(get(i,j),get(i,j)+n*m,1,-1);
            }
        }
    int flow,cost;
    EK(flow,cost);
    for(int i=1;i<=k;i++){
        dfs(get(1,1));
        for(int j=1;j<ans.size();j++) 
            if(ans[j]-ans[j-1]==m) cout<<i<<' '<<0<<endl;
            else cout<<i<<' '<<1<<endl;
        ans.clear();
    }
    return 0;
}