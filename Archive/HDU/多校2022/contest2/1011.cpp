#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

using LL=long long;
const int N=2e5+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
LL arr[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

namespace io {
    const int MAXBUF = 1e6, MAXLEN = 1e6;
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

    // template<typename... T> void reads_impl(T&... x) { (rd(x),...); }

    #define read(x) io::rd(x)
    // #define reads(...) io::reads_impl(__VA_ARGS__)

    const int MAXPBUF = 1e6, PRECISION = 7;
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

    // template<typename... T> void writes_impl(const T&... x) { (wt(x),...); }

    #define write(...) io::wt(__VA_ARGS__)
    // #define writes(...) io::writes_impl(__VA_ARGS__)

    struct Exit {
        ~Exit() { clear_buffer(); }
    } static exit;
}

struct Segment {
    struct Node {
        int l,r;
        LL v[10];
    };
    vector<Node> tr;

    void update(Node &p,Node l,Node r) {
        p.v[1]=max(l.v[1],r.v[1]);
        p.v[2]=max(l.v[2],r.v[2]);
        p.v[3]=max({l.v[3],r.v[3],l.v[1]+r.v[2]});
        p.v[4]=max({l.v[4],r.v[4],l.v[1]+r.v[8],l.v[3]+r.v[1],l.v[1]+r.v[3],l.v[6]+r.v[2]});
        p.v[5]=max({l.v[5],r.v[5],l.v[1]+r.v[7],l.v[3]+r.v[2],l.v[2]+r.v[3],l.v[8]+r.v[2]});
        p.v[6]=max({l.v[6],r.v[6],l.v[1]+r.v[1]});
        p.v[7]=max({l.v[7],r.v[7],l.v[2]+r.v[2]});
        p.v[8]=max({l.v[8],r.v[8],l.v[2]+r.v[1]});
        p.v[9]=max({l.v[9],r.v[9],l.v[1]+r.v[5],l.v[3]+r.v[3],l.v[4]+r.v[2],l.v[6]+r.v[7]});
    }

    void pushup(int u) { update(tr[u],tr[u<<1],tr[u<<1|1]); }

    Node query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) return tr[u];
        int mid=tr[u].l+tr[u].r>>1;
        Node res;
        if(mid>=l&&mid<r) update(res,query(u<<1,l,r),query(u<<1|1,l,r));
        else if(mid>=l) res=query(u<<1,l,r);
        else res=query(u<<1|1, l, r);
        return res;
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {
            tr[u].v[1]=arr[l],tr[u].v[2]=-arr[r];
            for(int i=3;i<=9;i++) tr[u].v[i]=-INF;
        }
        else {
            int mid=l+r>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }

    Segment(int sz) { tr.resize(sz*4+10); }
} segtr(N);

void solve() {
    int n=read(n),m=read(m);
    for(int i=1;i<=n;i++) read(arr[i]),arr[i]*=arr[i];
    segtr.build(1, 1, n);
    while(m--) {
        int l=read(l),r=read(r);
        write(segtr.query(1, l, r).v[9]),write('\n');
    }
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}