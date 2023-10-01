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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=8e5+10;
vector<int> adj[N],link[N];

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

struct DisjointUnionSet {
    vector<int> fa;

    void init(int n) {
        fa.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    bool join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        fa[y]=x;
        return true;
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
} dsu;

bool mark[N],ban[N];
vector<int> path,res;
void find(int rt,int u) {
    if(mark[u]) return;
    mark[u]=1;
    path.push_back(u);
    if(link[u].empty()) {
        for(int v:adj[u]) {
            v=dsu.find(v);
            if(mark[v]) continue;
            mark[v]=1;
            res.push_back(v);
        }
    }
    else for(int v:link[u]) find(rt,v);
}

void solve() {
    int n,m;
    io>>n>>m;
    for(int i=1;i<=n;i++) adj[i].clear(),link[i].clear(),ban[i]=0;
    dsu.init(n);
    for(int i=1;i<=m;i++) {
        int u,v;
        io>>u>>v;
        u++,v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    io>>q;
    while(q--) {
        int u;
        io>>u;
        u++;
        if(ban[u]||dsu.find(u)!=u) continue;
        
        path.clear();
        res.clear();
        find(u,u);
        for(int v:path) mark[v]=0;
        for(int v:res) mark[v]=0;
        link[u]=res;
        for(int v:res) dsu.join(u, v);
        debug(u,link[u]);
        if(res.empty()) ban[u]=1;
    }
    for(int i=1;i<=n;i++) io<<dsu.find(i)-1<<" \n"[i==n];
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    int t;
    io>>t;
    while(t--) solve();
    return 0;
}