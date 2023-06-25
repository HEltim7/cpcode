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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=5e4+10,M=1e5+10;

template
<class Info,class Tag,int MAX_SIZE,bool CHECK_LINK=0,bool CHECK_CUT=0>
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

    void pushdn(int u) {
        if(tr[u].rev) {
            swap(lch,rch);
            tr[lch].rev^=1,tr[rch].rev^=1;
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
        for(;u;v=u,u=tr[u].p)
            splay(u),rch=v,pushup(u);
        return v;
    }

    void make_root(int u) {
        access(u);
        splay(u);
        tr[u].rev^=1;
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
        if(CHECK_LINK&&find_root(v)==u) return assert(0),0;
        tr[u].p=v;
        return 1;
    }

    bool cut(int u,int v) {
        make_root(u);
        if(CHECK_CUT&&!(find_root(v)==u&&rch==v&&!tr[v].ch[0])) return assert(0),0;
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

    string dump_impl(int u) {
        string res;
        if(lch) res+=dump_impl(lch);
        res+=to_string(u)+" ";
        debug(u,lch,rch);
        if(rch) res+=dump_impl(rch);
        return res;
    }

    void dump() {
        for(int u=1;u<MAX_SIZE;u++) {
            if(is_root(u)&&(lch||rch)) {
                debug(u,dump_impl(u));
            }
        }
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
    int val=0,eid=-1;
    int maxv=0,maxid=-1;

    //* lch+parent+rch
    void pushup(const Info &l,const Info &r) {
        vector v({pair(l.maxv,l.maxid),pair(r.maxv,r.maxid),pair(val,eid)});
        sort(v.begin(),v.end());
        tie(maxv,maxid)=v.back();
    }

    void update(const Tag &x) {

    }
};

LinkCutTree<Info,Tag,N+M> lct;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int,int,int>> edg(m);
    for(auto &[a,b,u,v,w]:edg) cin>>u>>v>>a>>b;
    sort(edg.begin(),edg.end());

    for(int i=1;i<=m;i++) {
        auto &[a,b,u,v,w]=edg[i-1];
        w=i+n;
        lct.info(w)={b,i-1,b,i-1};
    }

    constexpr int INF=1e9;
    int ans=INF;

    for(auto [a,b,u,v,w]:edg) {
        if(lct.same(u,v)) {
            int rt=lct.split(u, v);
            int id=lct.info(rt).maxid;
            if(lct.info(rt).maxv>b) {
                auto [_,__,x,y,z]=edg[id];
                lct.cut(x, z);
                lct.cut(y, z);
                lct.link(u, w);
                lct.link(v, w);
            }
        }
        else {
            lct.link(u, w);
            lct.link(v, w);
        }
        if(lct.same(1, n)) ans=min(ans,lct.info(lct.split(1, n)).maxv+a);
    }

    cout<<(ans==INF?-1:ans)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}