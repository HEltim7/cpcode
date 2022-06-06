#include<iostream>
using namespace std;

#define endl '\n'
#define lch tr[x].ch[0]
#define rch tr[x].ch[1]
#define isr(x) (tr[tr[x].p].ch[1]==x)
typedef long long LL;
const int N=1e6+10;

struct NODE{
    int ch[2],p,val,id,size;
    inline void init(int P,int V,int ID){
        p=P,val=V,id=ID,size=1;
    }
} tr[N];
int fa[N],root[N],idx;

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

inline void pushup(int x){
    tr[x].size=tr[lch].size+tr[rch].size+1;
}

inline void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=isr(x);
    tr[z].ch[isr(y)]=x,tr[x].p=z;
    tr[y].ch[k]=tr[x].ch[k^1],tr[tr[y].ch[k]].p=y;
    tr[x].ch[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

inline void splay(int x,int k,int rt){
    for(int y;(y=tr[x].p)!=k;rotate(x))
        if(tr[y].p!=k) rotate(isr(x)^isr(y)?x:y);
    if(!k) root[rt]=x;
}

inline void insert(int v,int id,int rt){
    int x=root[rt],p=0;
    while(x) p=x,x=tr[x].ch[v>tr[x].val];
    x=++idx;
    tr[x].init(p,v,id);
    if(p) tr[p].ch[v>tr[p].val]=x;
    splay(x,0,rt);
}

inline int getk(int k,int x){
    for(;tr[x].size>=k;){
        if(tr[lch].size>=k) x=lch;
        else if(tr[lch].size+1==k) return tr[x].id;
        else k-=tr[lch].size+1,x=rch;
    }
    return -1;
}

void dfs(int x,int rt){
    if(lch) dfs(lch,rt);
    insert(tr[x].val,tr[x].id,rt);
    if(rch) dfs(rch,rt);
}

inline void merge(int a,int b){
    a=findfa(a),b=findfa(b);
    if(a!=b){
        if(tr[a].size>tr[b].size) swap(a,b);
        fa[a]=b;
        dfs(root[a],b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        fa[i]=i;
        insert(in,i,i);
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }
    cin>>q;
    while(q--){
        char op;
        int a,b;
        cin>>op>>a>>b;
        if(op=='B') merge(a,b);
        else cout<<getk(b,root[findfa(a)])<<endl;
    }
    return 0;
}