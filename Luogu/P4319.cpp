#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
using Edge=tuple<int,int,int,int>;
constexpr int N=5e4+10,D=32766,M=D*3+10;

template<class Info,int MAX_SIZE,
         bool CHECK_LINK = 0,bool CHECK_CUT = 0,bool ASSERT = 0>
struct LinkCutTree {
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)

    struct Node {
        int ch[2],p;
        bool rev;
        Info info;
    };
    array<Node, MAX_SIZE> tr;
    array<int, MAX_SIZE> stk;

    bool is_root(int u) {
        return tr[tr[u].p].ch[0]!=u&&tr[tr[u].p].ch[1]!=u;
    }

    void pushup(int u) {
        tr[u].info.pushup(tr[lch].info,tr[rch].info);
    }

    void pushrev(int u) {
        swap(lch,rch);
        tr[u].rev^=1;
    }

    void pushdn(int u) {
        if(tr[u].rev) {
            if(lch) pushrev(lch);
            if(rch) pushrev(rch);
            tr[u].rev=0;
        }
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

    int access(int u) {
        int v=0;
        for(;u;v=u,u=tr[u].p)
            splay(u),rch=v,pushup(u);
        return v;
    }

    void make_root(int u) {
        access(u);
        splay(u);
        pushrev(u);
    }

    int split(int u,int v) {
        make_root(u);
        access(v);
        splay(v);
        return v;
    }

    int find_root(int u) {
        access(u);
        splay(u);
        while(lch) pushdn(u),u=lch;
        splay(u);
        return u;
    }

    bool same(int u,int v) {
        make_root(u);
        return find_root(v)==u;
    }

    bool link(int u,int v) {
        make_root(u);
        if(CHECK_LINK&&find_root(v)==u)
            return assert(!ASSERT),0;
        tr[u].p=v;
        return 1;
    }

    bool cut(int u,int v) {
        make_root(u);
        if(CHECK_CUT&&!(find_root(v)==u&&rch==v&&!tr[v].ch[0]))
            return assert(!ASSERT),0;
        else access(v),splay(u);
        rch=tr[v].p=0;
        pushup(u);
        return 1;
    }

    int lca(int u,int v) {
        access(u);
        return access(v);
    }

    int lca(int rt,int u,int v) {
        make_root(rt);
        return lca(u,v);
    }

    Info &info(int u) {
        return tr[u].info;
    }

    #undef lch
    #undef rch
    #undef wch
};

struct Info {
    int val,maxv;
    int edg,maxe;

    //* lch+parent+rch
    void pushup(const Info &l,const Info &r) {
        if(l.maxv>=r.maxv) maxv=l.maxv,maxe=l.maxe;
        else maxv=r.maxv,maxe=r.maxe;
        if(val>maxv) maxv=val,maxe=edg;
    }
};

LinkCutTree<Info,N+N+M> lct;

#define lch (u<<1)
#define rch (u<<1|1)
vector<Edge> seg[D*4+10],edge(1);
LL ans[D+10];

void add(int u,int x,int y,int l,int r,Edge val) {
    if(x>r||y<l) return;
    if(x<=l&&y>=r) seg[u].emplace_back(val);
    else {
        int mid=(l+r)/2;
        add(lch,x,y,l,mid,val);
        add(rch,x,y,mid+1,r,val);
    }
}

LL sum;
void dfs(int u,int l,int r) {
    LL bak=sum;
    vector<Edge> del,add;
    
    for(auto [x,y,z,w]:seg[u]) {
        int rt=lct.split(x, y);
        if(lct.info(rt).maxv>w) {
            del.emplace_back(edge[lct.info(rt).maxe]);
            add.emplace_back(x,y,z,w);
            auto [a,b,c,d]=del.back();
            lct.cut(a, c);
            lct.cut(b, c);
            lct.link(x, z);
            lct.link(y, z);
            sum=sum-d+w;
        }
    }

    if(l==r) ans[l]=sum;
    else {
        int mid=(l+r)/2;
        dfs(lch, l, mid);
        dfs(rch, mid+1, r);
    }

    while(add.size()) {
        auto [x,y,z,w]=add.back();
        lct.cut(x, z);
        lct.cut(y, z);
        tie(x,y,z,w)=del.back();
        lct.link(x, z);
        lct.link(y, z);
        add.pop_back();
        del.pop_back();
    }
    sum=bak;
}

#undef lch
#undef rch

void solve() {
    int n;
    cin>>n;
    constexpr int offset=N+M;
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        u+=offset,v+=offset;
        Edge edg{u,v,i,w};
        edge.emplace_back(edg);
        lct.info(i)={w,w,i,i};
        lct.link(u, i);
        lct.link(v, i);
        sum+=w;
    }
    sum++;

    int m;
    cin>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w,l,r;
        cin>>u>>v>>w>>l>>r;
        u+=offset,v+=offset;
        Edge edg{u,v,i+n,w};
        edge.emplace_back(edg);

        if(u==v) continue;
        lct.info(i+n)={w,w,n+i-1,n+i-1};
        add(1, l, r, 1, D, edg);
    }

    dfs(1, 1, D);
    for(int i=1;i<=D;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}