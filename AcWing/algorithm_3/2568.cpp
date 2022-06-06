#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,M=N*2;
int h[N],w[N],e[M],ne[M],idx;
int id[N],nw[N],cnt;
int dep[N],sz[N],top[N],p[N],hch[N];
struct NODE{
    int l,r;
    LL add,sum;
} tr[N*4];

inline void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,ne[idx]=h[b],h[b]=idx++;
}

//深度优先遍历，算出深度、父节点、重儿子
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

//重链优先遍历，算出id、重链开头
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

inline void pushup(int x){
    tr[x].sum=tr[x<<1].sum+tr[x<<1|1].sum;
}

inline void pushdn(int x){
    auto &t=tr[x],&l=tr[x<<1],&r=tr[x<<1|1];
    l.sum+=(l.r-l.l+1)*t.add,l.add+=t.add;
    r.sum+=(r.r-r.l+1)*t.add,r.add+=t.add;
    t.add=0;
}

void modify(int x,int l,int r,int v){
    if(tr[x].l>=l&&tr[x].r<=r){
        tr[x].sum+=(tr[x].r-tr[x].l+1)*v;
        tr[x].add+=v;
    }
    else{
        pushdn(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(mid>=l) modify(x<<1,l,r,v);
        if(mid+1<=r) modify(x<<1|1,l,r,v);
        pushup(x);
    }
}

LL query(int x,int l,int r){
    if(tr[x].l>=l&&tr[x].r<=r) return tr[x].sum;
    pushdn(x);
    int mid=tr[x].l+tr[x].r>>1;
    LL res=0;
    if(mid>=l) res+=query(x<<1,l,r);
    if(mid+1<=r) res+=query(x<<1|1,l,r);
    return res;
}

void build(int x,int l,int r){
    tr[x]={l,r,0,nw[l]};
    if(l==r) return;
    int mid=l+r>>1;
    build(x<<1,l,mid),build(x<<1|1,mid+1,r);
    pushup(x);
}

void modify_path(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        modify(1,id[top[x]],id[x],k);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    modify(1,id[y],id[x],k);
}

void modify_tree(int x,int k){
    modify(1,id[x],id[x]+sz[x]-1,k);
}

LL query_path(int x,int y){
    LL res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res+=query(1,id[top[x]],id[x]);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    res+=query(1,id[y],id[x]);
    return res;
}

LL query_tree(int x){
    return query(1,id[x],id[x]+sz[x]-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    build(1,1,cnt);
    cin>>m;
    while(m--){
        int op,a,b,c;
        cin>>op;
        if(op==1){
            cin>>a>>b>>c;
            modify_path(a,b,c);
        }
        else if(op==2){
            cin>>a>>b;
            modify_tree(a,b);
        }
        else if(op==3){
            cin>>a>>b;
            cout<<query_path(a,b)<<endl;
        }
        else{
            cin>>a;
            cout<<query_tree(a)<<endl;
        }
    }
    return 0;
}