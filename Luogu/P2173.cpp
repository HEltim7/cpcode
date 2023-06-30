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
constexpr int N=1e4+10,M=1e5+10,C=12;

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
    int val,maxx;

    //* lch+parent+rch
    void pushup(const Info &l,const Info &r) {
        maxx=max({l.maxx,r.maxx,val});
    }

    void update(const Tag &x) {

    }

    void reverse() {}
};

array<LinkCutTree<Info,Tag,N>,C> lct;
array<array<int, C>, N> cnt;

void solve() {
    int n,m,c,q;
    cin>>n>>m>>c>>q;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        for(int j=0;j<c;j++) 
            lct[j].info(i)={in,in};
    }

    map<pair<int,int>,int> color;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        if(u>v) swap(u,v);
        color[{u,v}]=w;
        lct[w].link(u, v);
        cnt[u][w]++,cnt[v][w]++;
    }

    while(q--) {
        int k,u,v,w;
        cin>>k>>u>>v;
        if(k) cin>>w;
        if(k==0) {
            for(int j=0;j<c;j++) {
                lct[j].splay(u);
                lct[j].info(u).val=v;
            }
        }
        else if(k==1) {
            if(u>v) swap(u,v);
            if(color.find({u,v})==color.end()) {
                cout<<"No such edge."<<endl;
                continue;
            }

            int pre=color[{u,v}];
            if(pre==w) cout<<"Success."<<endl;
            else if(cnt[u][w]+1>2||cnt[v][w]+1>2) cout<<"Error 1."<<endl;
            else if(lct[w].same(u,v)) cout<<"Error 2."<<endl;
            else {
                cout<<"Success."<<endl;
                cnt[u][pre]--,cnt[v][pre]--;
                cnt[u][w]++,cnt[v][w]++;
                color[{u,v}]=w;
                lct[pre].cut(u, v);
                lct[w].link(u, v);
            }
        }
        else {
            if(lct[u].same(v, w))
                cout<<lct[u].info(lct[u].split(v,w)).maxx<<endl;
            else cout<<-1<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}