#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

using LL=long long;
using PII=pair<int,int>;
using PLI=pair<LL,int>;
const int N=1e6+10,M=N*3;
vector<PII> adj[M];
int n,k,p,s,t;
int dep[N];
int upper[N],lower[N],idx,maxdep;
LL dist[M];
bool vis[M];

void dfs(int u,int d,int fa) {
    dep[u]=d;
    maxdep=max(maxdep,d);
    for(auto x:adj[u]) {
        int v=x.first;
        if(v!=fa) dfs(v,d+1,u);
    }
}

void build() {
    for(int i=1;i<=maxdep;i++) upper[i]=++idx;
    for(int i=1;i<=maxdep;i++) lower[i]=++idx;
    for(int i=1;i<=n;i++) {
        if(dep[i]!=1) adj[i].emplace_back(upper[dep[i]],p);
        if(dep[i]!=maxdep) adj[i].emplace_back(lower[dep[i]],p);
        if(dep[i]-k>=1) adj[lower[dep[i]-k]].emplace_back(i,0);
        if(dep[i]+k<=maxdep) adj[upper[dep[i]+k]].emplace_back(i,0);
    }
}

LL dijkstra() {
    priority_queue<PLI,vector<PLI>,greater<PLI>> heap;
    memset(dist, 0x3f, sizeof (LL)*(n*3+5));
    memset(vis, 0, sizeof (bool)*(n*3+5));
    heap.emplace(0,s);
    dist[s]=0;
    while(heap.size()) {
        LL d=heap.top().first;
        int u=heap.top().second;
        heap.pop();
        if(vis[u]) continue;
        vis[u]=1;
        if(u==t) return d;
        for(auto x:adj[u]) {
            int v=x.first;
            int dis=x.second;
            if(d+dis<dist[v]) {
                dist[v]=d+dis;
                heap.emplace(dist[v],v);
            }
        }
    }
    return -1;
}

void solve() {
    int u,v,d;
    idx=read(n);
    maxdep=0;
    for(int i=1;i<n;i++) {
        reads(u,v,d);
        adj[u].emplace_back(v,d);
        adj[v].emplace_back(u,d);
    }
    reads(k,p,s,t);
    dfs(1,1,-1);
    build();
    writes(dijkstra(),'\n');
    for(int i=1;i<=idx;i++) adj[i].clear();
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}