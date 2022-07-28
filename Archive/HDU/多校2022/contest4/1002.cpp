#include <cstdio>
#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
const int N=1e5+10;

using LL=long long;
using PII=pair<int,int>;
using TIII=tuple<int,int,int>;

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

    template<typename T> void reads_impl(T& x) { rd(x); }
    template<typename T,typename... U> void reads_impl(T& x,U&... y) { rd(x),reads_impl(y...); }

    #define read(x) io::rd(x)
    #define reads(...) io::reads_impl(__VA_ARGS__)

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

    template<typename T> void writes_impl(const T& x) { wt(x); }
    template<typename T,typename... U> void writes_impl(const T& x,const U&... y) { wt(x),writes_impl(y...); }

    #define write(...) io::wt(__VA_ARGS__)
    #define writes(...) io::writes_impl(__VA_ARGS__)

    struct Exit {
        ~Exit() { clear_buffer(); }
    } static exit;
}

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

vector<TIII> adj[N];
vector<int> pre[N];
LL dist[N];
LL res[N];
int deg[N];
bool mark[N];
bool newg[N];

LL dijkstra(int n) {
    priority_queue<PII> heap;
    memset(dist, 0x3f, sizeof (LL)*(n+1));
    memset(mark, 0, sizeof (bool)*(n+1));
    dist[1]=0;
    heap.emplace(0,1);
    while(heap.size()) {
        LL d=heap.top().first;
        int u=heap.top().second;
        heap.pop();
        if(mark[u]) continue;
        mark[u]=1;
        for(TIII t:adj[u]) {
            int v=get<0>(t);
            int e=get<1>(t);
            int p=get<2>(t);
            if(dist[v]>d+e) pre[v].clear();
            if(dist[v]>=d+e) {
                dist[v]=d+e;
                pre[v].push_back(u);
                heap.emplace(dist[v],v);
            }
        }
    }
    debug(dist,1,n);
    return dist[n];
}

void build(int n) {
    memset(newg, 0, sizeof(bool)*(n+1));
    memset(deg, 0, sizeof(int)*(n+1));
    newg[n]=1;
    queue<int> q;
    q.push(n);
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:pre[u]) {
            deg[u]++;
            if(!newg[v]) q.push(v);
            newg[v]=1;
        }
    }
    debug(pre,1,n);
    debug(deg,1,n);
}

LL bfs(int n) {
    memset(res, 0xcf, sizeof(LL)*(n+1));
    queue<int> q;
    res[1]=0;
    q.push(1);
    while(q.size()) {
        int u=q.front();
        q.pop();
        debug(u);
        for(TIII t:adj[u]) {
            int v=get<0>(t);
            int e=get<1>(t);
            int p=get<2>(t);
            if(!newg[v]) continue;
            res[v]=max(res[v],res[u]+p);
            if(--deg[v]==0) q.push(v);
        }
    }
    return res[n];
}

void solve() {
    int n=read(n),m=read(m);
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) pre[i].clear();
    for(int i=1;i<=m;i++) {
        int a,b,e,p;
        reads(a,b,e,p);
        adj[a].emplace_back(b,e,p);
    }
    writes(dijkstra(n),' ');
    build(n);
    writes(bfs(n),'\n');
}

int main() {
    freopen("input2.txt", "r", stdin);
    int t=read(t);
    while(t--) solve();
    return 0;
}