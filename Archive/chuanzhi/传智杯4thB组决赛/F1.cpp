#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
typedef unsigned long long ULL;
const int N=1e6+10,M=N*2;
int h[N],e[M],ne[M],idx;
int id[N],cnt;
int dep[N],sz[N],top[N],p[N],hch[N];
ULL w[N],nw[N];
ULL tr[N];
int n,idx2;

#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

inline void add_edge(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,ne[idx]=h[b],h[b]=idx++;
}

void dfs1(int x,int fa,int d){
    dep[x]=d,p[x]=fa,sz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x,d+1);
        sz[x]+=sz[j];
        if(sz[hch[x]]<sz[j]) hch[x]=j;
    }
}

void dfs2(int x,int t){
    id[x]=++cnt,nw[cnt]=w[x],top[x]=t;
    if(!hch[x]) return;
    dfs2(hch[x],t);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==p[x]||j==hch[x]) continue;
        dfs2(j,j);
    }
}

inline void add(int pos,ULL val){
    while(pos<=n) tr[pos]^=val,pos+=lowbit(pos);
}

inline ULL __query(int pos){
    ULL res=0;
    while(pos) res^=tr[pos],pos-=lowbit(pos);
    return res;
}

inline ULL query(int a,int b){
    return __query(a-1)^__query(b);
}

bool query_path(int x,int y,ULL k){
    ULL res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        debug(id[top[x]],id[x]);
        res^=query(id[top[x]],id[x]);
        debug(res);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    res^=query(id[y],id[x]);
    debug(res);
    return res==k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    int m;
    cin>>n>>m;
    idx2=n+1;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b>>w[idx2];
        add_edge(a,idx2);
        add_edge(idx2,b);
        idx2++;
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    for(int i=1;i<=cnt;i++) add(i,nw[i]);

    while(m--){
        int a,b;
        ULL k;
        cin>>a>>b>>k;
        if(query_path(a,b,k)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}