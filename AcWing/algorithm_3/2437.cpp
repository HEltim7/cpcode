#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,INF=0x3f3f3f3f;

struct NODE{
    int c[2],p,val;
    int size,flag;
    void init(int a,int b){
        p=a,val=b,size=1;
    }
}tr[N];
int root,idx,n,m;

inline void pushup(int x){
    auto &t=tr[x];
    t.size=tr[t.c[0]].size+tr[t.c[1]].size+1;
}

inline void pushdn(int x){
    auto &t=tr[x];
    if(t.flag){
        swap(t.c[0],t.c[1]);
        tr[t.c[0]].flag^=1;
        tr[t.c[1]].flag^=1;
        t.flag=0;
    }
}

inline void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=tr[y].c[1]==x;
    tr[z].c[tr[z].c[1]==y]=x,tr[x].p=z;
    tr[y].c[k]=tr[x].c[k^1],tr[tr[y].c[k]].p=y;
    tr[x].c[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

inline void splay(int x,int k){
    for(int y,z;(y=tr[x].p)!=k;rotate(x))
        if((z=tr[y].p)!=k) rotate((x==tr[y].c[1])^(y==tr[z].c[1])?x:y);
    if(!k) root=x;
}

inline int getk(int k){
    int x=root;
    for(;;){
        pushdn(x);
        if(tr[tr[x].c[0]].size>=k) x=tr[x].c[0];
        else if(tr[tr[x].c[0]].size+1==k) return x;
        else k-=tr[tr[x].c[0]].size+1,x=tr[x].c[1];
    }
    return -1;
}

inline void insert(int v){
    int x=root,p=0;
    while(x) p=x,x=tr[x].c[v>tr[x].val];
    x=++idx;
    if(p) tr[p].c[v>tr[p].val]=x;
    tr[x].init(p,v);
    splay(x,0);
}

void output(int x){
    pushdn(x);
    auto &t=tr[x];
    if(t.c[0]) output(t.c[0]);
    if(t.val>=1&&t.val<=n) cout<<t.val<<' ';
    if(t.c[1]) output(t.c[1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n+1;i++) insert(i);
    while(m--){
        int l,r;
        cin>>l>>r;
        l=getk(l),r=getk(r+2);
        splay(l,0),splay(r,l);
        tr[tr[r].c[0]].flag^=1;
    }
    output(root);
    return 0;
}