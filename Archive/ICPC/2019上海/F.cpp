#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=1e5+10,M=N*2,mod=1e9+7,INF=0x3f3f3f3f;
int h[N],w[N],e[M],ne[M],idx;
int id[N],nw[N],cnt;
int dep[N],sz[N],top[N],p[N],hch[N];
struct NODE{
    int l,r;
    LL w1,w2,w3;
    LL upd,mul,add;
} tr[N*4];

inline void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,ne[idx]=h[b],h[b]=idx++;
}

inline void pushup(int x){
    auto &p=tr[x],&l=tr[x<<1],&r=tr[x<<1|1];
    p.w1=(l.w1+r.w1)%mod;
    p.w2=(l.w2+r.w2)%mod;
    p.w3=(l.w3+r.w3)%mod;
}

inline void update(int x,LL upd,LL mul,LL add){
    auto &t=tr[x];
    LL c,c2,c3;
    LL len=t.r-t.l+1;
    if(upd!=INF){
        c=upd,c2=upd*upd%mod,c3=c2*upd%mod;
        t.w1=len*c%mod;
        t.w2=len*c2%mod;
        t.w3=len*c3%mod;
        t.upd=upd;
        t.mul=1;
        t.add=0;
    }

    c=mul,c2=mul*mul%mod,c3=c2*mul%mod;
    t.w3=t.w3*c3%mod;
    t.w2=t.w2*c2%mod;
    t.w1=t.w1*c%mod;
    t.mul=t.mul*mul%mod;

    c=add,c2=add*add%mod,c3=c2*add%mod;
    t.w3=(t.w3+3*c*t.w2%mod+3*c2*t.w1%mod+len*c3%mod)%mod;
    t.w2=(t.w2+2*c*t.w1%mod+len*c2%mod)%mod;
    t.w1=(t.w1+len*c%mod)%mod;
    t.add=(t.add*mul%mod+add)%mod;
}

inline void pushdn(int x){
    auto &t=tr[x];
    update(x<<1,t.upd,t.mul,t.add);
    update(x<<1|1,t.upd,t.mul,t.add);
    t.upd=INF;
    t.mul=1;
    t.add=0;
}

void modify(int x,int l,int r,int op,LL v){
    if(tr[x].l>=l&&tr[x].r<=r){
        if(op==1) update(x,v,1,0);
        else if(op==2) update(x,INF,1,v);
        else update(x,INF,v,0);
    }
    else{
        pushdn(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(mid>=l) modify(x<<1,l,r,op,v);
        if(mid<r) modify(x<<1|1,l,r,op,v);
        pushup(x);
    }
}

LL query(int x,int l,int r){
    if(tr[x].l>=l&&tr[x].r<=r) return tr[x].w3;
    int mid=tr[x].l+tr[x].r>>1;
    LL res=0;
    pushdn(x);
    if(mid>=l) res=query(x<<1,l,r);
    if(mid<r) res+=query(x<<1|1,l,r);
    return res%mod;
}

void build(int x,int l,int r){
    tr[x]={l,r,0,0,0,INF,1,0};
    if(l==r){
        tr[x].w1=nw[l];
        tr[x].w2=1LL*nw[l]*nw[l]%mod;
        tr[x].w3=1LL*tr[x].w2*nw[l]%mod;
    }
    else{
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        pushup(x);
    }
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

void modify_path(int x,int y,int op,LL v){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        modify(1,id[top[x]],id[x],op,v);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    modify(1,id[y],id[x],op,v);
}

LL query_path(int x,int y){
    LL res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res=(res+query(1,id[top[x]],id[x]))%mod;
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    res+=query(1,id[y],id[x]);
    return res%mod;
}

void solve(){
    memset(h,-1,sizeof h);
    memset(hch,0,sizeof hch);
    int n,q;
    idx=cnt=0;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    dfs1(1,-1,1);
    dfs2(1,1);
    build(1,1,cnt);
    
    cin>>q;
    while(q--){
        int op,a,b,c;
        cin>>op>>a>>b;
        if(op!=4){
            cin>>c;
            modify_path(a,b,op,c);
        }
        else cout<<query_path(a,b)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<":"<<endl;
        solve();
    }
    return 0;
}