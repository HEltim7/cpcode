#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
int id[N],p[N],hch[N],top[N],sz[N],dep[N],cnt;
struct NODE{
    int l,r,flag,sum;
} tr[N*4];

inline void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

inline void pushup(int x){
    tr[x].sum=tr[x<<1].sum+tr[x<<1|1].sum;
}

inline void pushdn(int x){
    if(tr[x].flag==-1) return;
    auto &t=tr[x],&l=tr[x<<1],&r=tr[x<<1|1];
    l.sum=(l.r-l.l+1)*t.flag,l.flag=t.flag;
    r.sum=(r.r-r.l+1)*t.flag,r.flag=t.flag;
    t.flag=-1;
    pushup(x);
}

void modify(int x,int l,int r,int v){
    if(tr[x].l>=l&&tr[x].r<=r){
        tr[x].sum=v*(tr[x].r-tr[x].l+1);
        tr[x].flag=v;
    }
    else{
        pushdn(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(l<=mid) modify(x<<1,l,r,v);
        if(r>mid) modify(x<<1|1,l,r,v);
        pushup(x);
    }
}

void build(int x,int l,int r){
    tr[x]={l,r,-1,0};
    if(l==r) return;
    int mid=l+r>>1;
    build(x<<1,l,mid),build(x<<1|1,mid+1,r);
    pushup(x);
}

void dfs1(int x,int fa,int d){
    p[x]=fa,dep[x]=d,sz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
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

void install(int x){
    while(top[x]!=1){
        modify(1,id[top[x]],id[x],1);
        x=p[top[x]];
    }
    modify(1,id[1],id[x],1);
}

void uninstall(int x){
    modify(1,id[x],id[x]+sz[x]-1,0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    int n,q;
    cin>>n;
    for(int i=2;i<=n;i++){
        int in;
        cin>>in;
        add(in+1,i);
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    build(1,1,cnt);
    cin>>q;
    while(q--){
        string op;
        int x,pre=0;
        cin>>op>>x;
        pre=tr[1].sum;
        if(op=="install") install(x+1);
        else uninstall(x+1);
        cout<<abs(pre-tr[1].sum)<<endl;
    }
    return 0;
}