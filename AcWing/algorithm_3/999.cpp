#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

#define endl '\n'
#define lch tr[x].ch[0]
#define rch tr[x].ch[1]
#define isr(x) (tr[tr[x].p].ch[1]==x)
typedef long long LL;
const int N=2e5,INF=0x3f3f3f3f;
struct EDGE
{
    int a,b,x,y;
    bool operator< (const EDGE &e) const{
        return a<e.a;
    }
} edge[N];
struct NODE
{
    int ch[2],p,v;
    int maxi,rev;
} tr[N];
int fa[N],stk[N];

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

inline void pushup(int x){
    tr[x].maxi=x;
    if(tr[tr[lch].maxi].v>tr[tr[x].maxi].v) tr[x].maxi=tr[lch].maxi;
    if(tr[tr[rch].maxi].v>tr[tr[x].maxi].v) tr[x].maxi=tr[rch].maxi;
}

inline void pushrev(int x){
    swap(lch,rch);
    tr[x].rev^=1;
}

inline void pushdn(int x){
    if(tr[x].rev) pushrev(lch),pushrev(rch),tr[x].rev=0;
}

inline bool isroot(int x){
    return tr[tr[x].p].ch[0]!=x&&tr[tr[x].p].ch[1]!=x;
}

inline void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=isr(x);
    if(!isroot(y)) tr[z].ch[isr(y)]=x;
    tr[x].p=z;
    tr[y].ch[k]=tr[x].ch[!k],tr[tr[y].ch[k]].p=y;
    tr[x].ch[!k]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

inline void splay(int x){
    int top=0,p=x;
    stk[++top]=p;
    while(!isroot(p)) stk[++top]=p=tr[p].p;
    while(top) pushdn(stk[top--]);
    for(int y;!isroot(x);rotate(x))
        if(!isroot(y=tr[x].p)) rotate(isr(y)^isr(x)?x:y);
}

inline void access(int x){
    int z=x;
    for(int y=0;x;y=x,x=tr[x].p){
        splay(x);
        rch=y;pushup(x);
    }
    splay(z);
}

inline void makeroot(int x){
    access(x);
    pushrev(x);
}

inline int findroot(int x){
    access(x);
    while(lch) pushdn(x),x=lch;
    splay(x);
    return x;
}

inline void link(int x,int y){
    makeroot(x);
    if(findroot(y)!=x) tr[x].p=y;
}

inline void cut(int x,int y){
    makeroot(x);
    if(findroot(y)==x&&rch==y&&!tr[y].ch[0]){
        rch=tr[y].p=0;
        pushup(x);
    }
}

inline void split(int x,int y){
    makeroot(x);
    access(y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,ans=INF;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>edge[i].x>>edge[i].y>>edge[i].a>>edge[i].b;
    sort(edge+1,edge+1+m);
    for(int i=1;i<=n+m;i++){
        fa[i]=i;
        if(i>n) tr[i].v=edge[i-n].b;
        tr[i].maxi=i;
    }
    for(int i=1;i<=m;i++){
        auto [a,b,x,y]=edge[i];
        if(findfa(x)==findfa(y)){
            split(x,y);
            int t=tr[y].maxi;
            if(tr[t].v>b){
                cut(edge[t-n].x,t),cut(t,edge[t-n].y);
                link(x,n+i),link(n+i,y);
            }
        }
        else link(x,n+i),link(n+i,y),fa[findfa(x)]=findfa(y);
        if(findfa(1)==findfa(n)){
            split(1,n);
            ans=min(ans,a+tr[tr[n].maxi].v);
        }
    }
    if(ans==INF) ans=-1;
    cout<<ans;
    return 0;
}