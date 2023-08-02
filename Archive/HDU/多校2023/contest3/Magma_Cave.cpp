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
using Edge=tuple<int,int,int>;
constexpr int N=5e4+10,M=2e5+10;

namespace fast_io {
    constexpr int MAXBUF = 1 << 20, MAXLEN = 1 << 20;
    char buf[MAXBUF], *pl, *pr;
    char str[MAXLEN];

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T> T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        if (c != '.') return x = x * f;
        for (double t = 0.1; c = gc(), isdigit(c); t *= 0.1) x += (c - '0') * t;
        return x = x * f;
    }

    char* rd(char *p = str) {
        char c = gc(), *h = p;
        while (!isgraph(c)) c = gc();
        while (isgraph(c)) *p++ = c, c = gc();
        *p = '\0';
        return h;
    }

    char rd(char &c) {
        c = gc();
        while (!isgraph(c)) c = gc();
        return c;
    }

    string rd(string &s) { return s = rd(str); }

    template<typename... T> auto read(T&... x) { return (rd(x),...); }
    #undef gc

    constexpr int MAXPBUF = 1 << 20, PRECISION = 7;
    char pbuf[MAXPBUF], *pp = pbuf;

    void clear_buffer() { fwrite(pbuf, 1, pp-pbuf, stdout), pp = pbuf; }

    void push(const char &c) {
        if (pp - pbuf == MAXPBUF) clear_buffer();
        *pp++ = c;
    }

    template<typename T> void wt(T x) {
        if (x < 0) push('-'), x = -x;
        static int sta[40];
        int top = 0;
        do {
            sta[top++] = x % 10;
        } while (x/=10);
        while (top) push(sta[--top] + '0');
    }

    template<typename T> void wt_f(T x,int p) {
        if (x < 0) push('-'), x = -x;
        long long pre = (long long)x;
        wt(pre);
        x -= pre;
        if (p) push('.');
        while (p--) {
            x *= 10;
            int t = (int)x;
            x -= t;
            push(t + '0');
        }
    }

    void wt(const char &c) { push(c); }
    void wt(const string &s) { for (auto &x:s) push(x); }
    void wt(const char *p) { while (*p != '\0') push(*p++); }

    void wt(const float &x, int p = PRECISION) { wt_f(x,p); }
    void wt(const double &x, int p = PRECISION) { wt_f(x,p); }
    void wt(const long double &x, int p = PRECISION) { wt_f(x,p); }

    template<typename... T> void write(const T&... x) { (wt(x),...); }
    template<typename T> void writef(const T &x,const int &p) { wt_f(x,p); }

    struct IO {
        template<typename T> friend IO& 
        operator>>(IO &io, T& x) { rd(x); return io; }

        template<typename T> friend IO&
        operator<<(IO &io, const T& x) { wt(x); return io; }

        ~IO() { clear_buffer(); }
    } static io;

} using fast_io::read,fast_io::write,fast_io::writef,fast_io::io;

template<class Info,class Tag,
         bool CHECK_LINK = 0,bool CHECK_CUT = 0,bool ASSERT = 0>
struct LinkCutTree {
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)

    LinkCutTree(int n) {
        tr.resize(n+5);
        stk.resize(n+5);
    }

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
    vector<Node> tr;
    vector<int> stk;

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

struct MinInfo {
    int w=M,minw=M;
    Edge e,mine;

    //* lch+parent+rch
    void pushup(const MinInfo &l,const MinInfo &r) {
        if(l.minw<r.minw) minw=l.minw,mine=l.mine;
        else minw=r.minw,mine=r.mine;
        if(w<minw) minw=w,mine=e;
    }

    void update(const Tag &x) {

    }

    void reverse() {}
};

struct MaxInfo {
    int w,maxw;
    Edge e,maxe;

    //* lch+parent+rch
    void pushup(const MaxInfo &l,const MaxInfo &r) {
        if(l.maxw>=r.maxw) maxw=l.maxw,maxe=l.maxe;
        else maxw=r.maxw,maxe=r.maxe;
        if(w>maxw) maxw=w,maxe=e;
    }

    void update(const Tag &x) {

    }

    void reverse() {}
};

template<typename T=int,T init=T()> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=init;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    void resize(int n) {
        size=n;
        tr.resize(size+1,init);
    }

    Fenwick()=default;
    Fenwick(int n):size(n) { tr.resize(size+1,init); }
};

void solve() {
    int n,q,cnt=0;
    io>>n>>q;
    set<int> st;
    Fenwick<int> minfen(n+q+5),maxfen(n+q+5);
    LinkCutTree<MinInfo,Tag> maxst(n+q);
    LinkCutTree<MaxInfo,Tag> minst(n+q);

    for(int i=1;i<=q;i++) {
        int op=read(op);
        if(op==1) {
            int x,y,w;
            io>>x>>y>>w;
            int z=n+i;
            st.insert(w);
            
            maxst.info(z)={w,w,{x,y,z},{x,y,z}};
            if(maxst.same(x, y)) {
                int rt=maxst.split(x, y);
                int minw=maxst.info(rt).minw;
                auto [a,b,c]=maxst.info(rt).mine;
                if(minw<w) {
                    maxst.cut(a, c);
                    maxst.cut(b, c);
                    maxst.link(x, z);
                    maxst.link(y, z);
                    maxfen.add(w, 1);
                    maxfen.add(minw, -1);
                }
            }
            else {
                maxst.link(x, z);
                maxst.link(y, z);
                maxfen.add(w, 1);
                cnt++;
            }

            minst.info(z)={w,w,{x,y,z},{x,y,z}};
            if(minst.same(x, y)) {
                int rt=minst.split(x, y);
                int maxw=minst.info(rt).maxw;
                auto [a,b,c]=minst.info(rt).maxe;
                if(maxw>w) {
                    minst.cut(a, c);
                    minst.cut(b, c);
                    minst.link(x, z);
                    minst.link(y, z);
                    minfen.add(w, 1);
                    minfen.add(maxw, -1);
                }
            }
            else {
                minst.link(x, z);
                minst.link(y, z);
                minfen.add(w, 1);
            }
        }
        else {
            int k,w;
            io>>k>>w;
            if(cnt+1<n||!st.count(w)) io<<"NO"<<endl;
            else {
                int v=minfen.query(w)-minfen.query(w-1);
                int l=maxfen.query(w-1);
                int r=minfen.query(w-1)-!v;
                if(k>=l+1&&k<=r+1) io<<"YES"<<endl;
                else io<<"NO"<<endl;
            }
        }
    }
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}