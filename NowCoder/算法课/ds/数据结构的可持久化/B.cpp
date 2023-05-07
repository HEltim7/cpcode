#include <algorithm>
#include <array>
#include <cassert>
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
constexpr int N=2e6+10;

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

template<int node_size,int root_size,int rng_l,int rng_r>
struct PersistentSegmentTree {
    #define lch(u) (tr[u].ch[0])
    #define rch(u) (tr[u].ch[1])

    struct Node {
        int cnt;
        int ch[2];
    };

    array<int, root_size> root;
    array<Node, node_size> tr;
    int idx,ver;

    int new_node() {
        assert(idx<node_size);
        return ++idx;
    }

    void pushup(int u) {
        tr[u].cnt=tr[lch(u)].cnt+tr[rch(u)].cnt;
    }

    int query(int u,const int ql,const int qr,int l=rng_l,int r=rng_r) {
        if(l>=ql&&r<=qr) { return tr[u].cnt; }
        else {
            int mid=(l+r)/2;
            if(mid>=ql&&mid<qr) 
                return query(lch(u),ql,qr,l,mid)+query(rch(u),ql,qr,mid+1,r);
            else if(mid>=ql) return query(lch(u),ql,qr,l,mid);
            return query(rch(u),ql,qr,mid+1,r);
        }
    }

    void modify(int &u,int v,int p,const int &val,int l=rng_l,int r=rng_r) {
        u=new_node();
        tr[u]=tr[v];
        if(l==r) tr[u].cnt=val;
        else {
            int mid=(l+r)/2;
            if(p<=mid) modify(lch(u),lch(v),p,val,l,mid);
            else modify(rch(u),rch(v),p,val,mid+1,r);
            pushup(u);
        }
    }

    void append(int p,const int &val) {
        ver++;
        modify(root[ver],root[ver-1],p,val);
    }

    void build(int &u,int l,int r) {
        u=new_node();
        if(l!=r) {
            int mid=l+r>>1;
            build(lch(u),l,mid);
            build(rch(u),mid+1,r);
            pushup(u);
        }
    }
    void build() { build(root[0],rng_l,rng_r); }

    #undef lch
    #undef rch
};
PersistentSegmentTree<N*__lg(N)*4, N*3, 1, N> sgt;

int last[N][2];
int rtid[N];

void solve() {
    int n,q;
    io>>n>>q>>q;
    sgt.build();
    for(int i=1;i<=n;i++) {
        int in;
        io>>in;
        if(last[in][0]) sgt.append(last[in][0], int{0});
        last[in][0]=last[in][1];
        last[in][1]=i;
        if(last[in][0]) sgt.append(last[in][0], int{1});
        rtid[i]=sgt.ver;
    }

    while(q--) {
        int l,r;
        io>>l>>r;
        io<<sgt.query(sgt.root[rtid[r]], l, N)<<endl;
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    solve();
    return 0;
}