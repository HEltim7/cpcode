#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=3e5+10;
auto gen=mt19937_64(random_device()());
using R=decltype(gen());

template
<class Info,class Tag,int MAX_SIZE,bool CHECK_LINK=0,bool CHECK_CUT=0>
struct LinkCutTree {
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)
    constexpr static bool ASSERT=true;

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
        for(;u;v=u,u=tr[u].p) {
            splay(u);
            if(rch) tr[u].info.add(info(rch));
            if(v) tr[u].info.sub(info(v));
            rch=v,pushup(u);
        }
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

    bool link(int p,int u) {
        make_root(u);
        if(CHECK_LINK&&find_root(p)==u)
            return assert(!ASSERT),0;
        make_root(p);
        tr[p].info.add(info(u));
        tr[u].p=p;
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
    R val=0,sum=0,vsum=0;

    //* lch+parent+rch
    void pushup(const Info &l,const Info &r) {
        sum=l.sum^r.sum^vsum^val;
    }

    void update(const Tag &x) {

    }

    void add(const Info &x) {
        vsum^=x.sum;
    }

    void sub(const Info &x) {
        add(x);
    }
};

LinkCutTree<Info,Tag,int(1e5)+10> lct;

void solve() {
    int n,m;
    cin>>n>>m;

    auto apply=[&](int u,R val) {
        lct.access(u);
        lct.splay(u);
        lct.info(u).val^=val;
    };

    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        lct.link(u,v);
    }

    R sum=0;
    int cnt=0;
    map<int,tuple<int,int,R>> mp;

    while(m--) {
        int op,x,y,u,v;
        cin>>op;
        if(op==1) {
            cin>>x>>y>>u>>v;
            lct.cut(x,y);
            lct.link(u,v);
        }
        else if(op==2) {
            cin>>x>>y;
            if(x>y) swap(x,y);
            R r=gen();
            apply(x,r);
            apply(y,r);
            sum^=r;
            mp.emplace(++cnt,tuple{x,y,r});
        }
        else if(op==3) {
            cin>>x;
            auto [u,v,r]=mp[x];
            mp.erase(x);
            apply(u,r);
            apply(v,r);
            sum^=r;
        }
        else {
            cin>>x>>y;
            lct.cut(x,y);
            R a=lct.info(x).sum;
            R b=lct.info(y).sum;
            if(a==b&&b==sum) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            lct.link(x,y);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int id;
    cin>>id;
    solve();
    return 0;
}