#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
constexpr int N=1e5+10;

template<class Info,class Tag,int MAX_SIZE,
         bool CHECK_LINK = 0,bool CHECK_CUT = 0,bool ASSERT = 0>
struct LinkCutTree {
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)

    struct Node {
        int ch[2],p;
        bool rev;
        Info info;
        Tag tag;
        void update(const Tag &x) {
            info.update(x);
            tag.update(x);
        }
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
        tr[u].info.reverse();
        swap(lch,rch);
        tr[u].rev^=1;
    }

    void pushdn(int u) {
        if(tr[u].rev) {
            if(lch) pushrev(lch);
            if(rch) pushrev(rch);
            tr[u].rev=0;
        }
        if(lch) tr[lch].update(tr[u].tag);
        if(rch) tr[rch].update(tr[u].tag);
        tr[u].tag.clear();
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
        for(;u;v=u,u=tr[u].p) {
            splay(u);
            if(rch) info(u).add(info(rch));
            if(v) info(u).sub(info(v));
            rch=v,pushup(u);
        }
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

    bool link(int p,int u) {
        make_root(u);
        if(CHECK_LINK&&find_root(p)==u)
            return assert(!ASSERT),0;
        make_root(p);
        info(p).add(info(u));
        tr[u].p=p;
        pushup(p);
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

    void modify(int u,const Tag &x) {
        if(!is_root(u)) splay(u);
        tr[u].update(x);
    }

    Info &info(int u) {
        return tr[u].info;
    }

    int find(int u) {
        int lsz=0,rsz=0,tot=info(u).sz;
        int res=1e9,cnt=2-(tot&1);
        while(u) {
            pushdn(u);
            int l=lsz+info(lch).sz;
            int r=rsz+info(rch).sz;
            if(l<=tot/2&&r<=tot/2) {
                res=min(res,u);
                if(--cnt==0) break;
            }
            if(l<r) {
                lsz+=info(lch).sz+info(u).vsz+1;
                u=rch;
            }
            else {
                rsz+=info(rch).sz+info(u).vsz+1;
                u=lch;
            }
        }
        splay(res);
        return res;
    }

    #undef lch
    #undef rch
    #undef wch
};

struct Tag {

    void update(const Tag &x) {
        
    }

    void clear() {
        
    }
};

struct Info {
    int sz=0,vsz=0;

    void pushup(const Info &l,const Info &r) {
        sz=l.sz+r.sz+vsz+1;
    }

    void add(const Info &x) {
        vsz+=x.sz;
    }

    void sub(const Info &x) {
        vsz-=x.sz;
    }

    void update(const Tag &x) {

    }

    void reverse() {}
};

LinkCutTree<Info,Tag,N> lct;

struct DisjointUnionSet {
    vector<int> fa,sz,cen;

    void init(int n) {
        fa.resize(n+1);
        sz.assign(n+1,1);
        iota(fa.begin(), fa.end(), 0);
        cen=fa;
    }

    int find(int x) {
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    bool join(int x,int y,int c) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        sz[x]+=sz[y];
        fa[y]=x;
        cen[x]=cen[y]=c;
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }

    int centroid(int x) {
        return cen[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
};

void solve() {
    int n,m,xsum=0;
    cin>>n>>m;
    DisjointUnionSet dsu(n);
    for(int i=1;i<=n;i++) xsum^=i,lct.info(i).sz=1;
    while(m--) {
        string op;
        int x,y;
        cin>>op;
        if(op.front()=='X') cout<<xsum<<endl;
        else if(op.front()=='Q') {
            cin>>x;
            cout<<dsu.centroid(x)<<endl;
        }
        else {
            cin>>x>>y;
            lct.link(x, y);
            x=dsu.centroid(x);
            y=dsu.centroid(y);
            int rt=lct.split(x, y);
            int c=lct.find(rt);
            dsu.join(x, y, c);
            xsum^=x^y^c;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}