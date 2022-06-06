#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef unsigned long long ULL;
const int N=1e6+10,M=N*2;
int h[N],e[M],ne[M],idx;
int id[N],cnt;
int dep[N],sz[N],top[N],p[N],hch[N];
ULL w[N],nw[N];
ULL tr[N];
int n;
// map<pair<int,int>,ULL> st;

inline void add_edge(int a,int b,ULL c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,w[idx]=c,ne[idx]=h[b],h[b]=idx++;
}

void dfs1(int x,int fa,int d){
    dep[x]=d,p[x]=fa,sz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        nw[j]=w[i];
        dfs1(j,x,d+1);
        sz[x]+=sz[j];
        if(sz[hch[x]]<sz[j]) hch[x]=j;
    }
}

void dfs2(int x,int t){
    id[x]=++cnt,top[x]=t;
    if(!hch[x]) return;
    dfs2(hch[x],t);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==p[x]||j==hch[x]) continue;
        dfs2(j,j);
    }
}

int getfa(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    return y;
}

ULL getpath(int x,int fa){
    ULL res=0;
    while(x!=fa){
        res^=nw[x];
        x=p[x];
    }
    return res;
}

inline bool check(int a,int b,ULL k){
    int fa=getfa(a,b);
    ULL res=0;
    if(fa==a) res=getpath(b,fa);
    else if(fa==b) res=getpath(a,fa);
    else res=getpath(a,fa)^getpath(b,fa);
    return res==k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    int m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b;
        ULL c;
        cin>>a>>b>>c;
        add_edge(a,b,c);
    }
    dfs1(1,-1,1);
    dfs2(1,1);

    while(m--){
        int a,b;
        ULL k;
        cin>>a>>b>>k;
        if(check(a,b,k)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}