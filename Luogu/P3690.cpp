#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

struct LinkCutTree {
    
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)
    constexpr static int MAX_SIZE=1e5+10;

    struct Node {
        int ch[2],p;
        bool rev;
        int val,sum;
    } tr[MAX_SIZE];
    int stk[MAX_SIZE];

    bool is_root(int u) {
        return tr[tr[u].p].ch[0]!=u&&tr[tr[u].p].ch[1]!=u;
    }

    void pushup(int u) {
        tr[u].sum=tr[u].val^tr[lch].sum^tr[rch].sum;
    }

    void pushrev(int u) {
        swap(lch,rch);
        tr[u].rev^=1;
    }

    void pushdn(int u) {
        if(tr[u].rev) pushrev(lch),pushrev(rch),tr[u].rev=0;
    }

    void rotate(int x) {
        int y=tr[x].p,z=tr[y].p,k=wch(x);
        if(!is_root(y)) tr[z].ch[wch(y)]=x;
        tr[y].ch[k]=tr[x].ch[!k],tr[tr[y].ch[k]].p=y;
        tr[x].ch[!k]=y,tr[y].p=x,tr[x].p=z;
        pushup(y),pushup(x);
    }

    void splay(int u) {
        int top=0,fa=u;
        stk[++top]=fa;
        while(!is_root(fa)) stk[++top]=fa=tr[fa].p;
        while(top) pushdn(stk[top--]);
        for(;!is_root(u);rotate(u))
            if(!is_root(fa=tr[u].p)) rotate(wch(u)==wch(fa)?fa:u);
    }

    void access(int u) {
        int t=u;
        for(int v=0;u;v=u,u=tr[u].p)
            splay(u),tr[u].ch[1]=v,pushup(u);
        splay(t);
    }

    void make_root(int u) {
        access(u);
        pushrev(u);
    }

    int split(int u,int v) {
        make_root(u);
        access(v);
        return v;
    }

    int find_root(int u) {
        access(u);
        while(lch) pushdn(u),u=lch;
        splay(u);
        return u;
    }

    void link(int u,int v) {
        make_root(u);
        if(find_root(v)!=u) tr[u].p=v;
    }

    void cut(int u,int v) {
        make_root(u);
        if(find_root(v)==u&&rch==v&&!tr[v].ch[0])
            rch=tr[v].p=0,pushup(u);
    }

    #undef lch
    #undef rch
    #undef wch

} lct;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>lct.tr[i].val,lct.pushup(i);
    while(m--) {
        int op,u,v;
        cin>>op>>u>>v;
        if(op==0) {
            lct.split(u, v);
            cout<<lct.tr[v].sum<<endl;
        }
        else if(op==1) lct.link(u,v);
        else if(op==2) lct.cut(u,v);
        else {
            lct.splay(u);
            lct.tr[u].val=v;
            lct.pushup(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}