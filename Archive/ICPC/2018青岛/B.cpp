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
#include <stack>
#include <tuple>
#include <utility>
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
constexpr int N = 1e5 + 10;

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

struct Tarjan {
    int n,dn,bn,index;
    vector<vector<pair<int,int>>> g;
    vector<vector<int>> ecc;
    vector<int> dfn,low,bel;
    stack<int> st;
    vector<int> a;
    Tarjan(int n, const vector<int>& a)
    : n(n),dn(0),bn(0),index(0),g(n),dfn(n),low(n),bel(n), a(a) {}
    void addEdge(int u,int v) {
        g[u].emplace_back(v,index++);
        g[v].emplace_back(u,index++);
    }
    void tarjan(int u,int index) {
        dfn[u]=low[u]=++dn;
        st.push(u);
        for(auto [v,i]:g[u]) {
            if((i^1)==index)// 防止立马回头
                continue;
            if(!dfn[v]) {
                tarjan(v,i);
                low[u]=min(low[u], low[v]);
                // if(dfn[u]<low[v]) {}// 割边
            }else {
                low[u]=min(low[u], dfn[v]);// 返祖边
            }
        }
        if(dfn[u]==low[u]) {
            vector<int> cur;
            for(int v=-1; v!=u; ) {
                v=st.top();
                st.pop();
                bel[v]=bn;
                cur.push_back(a[v]);// 连通分量的信息
            }
            ecc.emplace_back(cur);
            bn++;
        }
    }
    void converge() {
        for(int i=0; i<n; ++i)
            if(!dfn[i]) tarjan(i,-1);
    }
    auto newForest() {
        vector<vector<pair<int,int>>> forest(bn);
        for(int u=0; u<n; ++u)
            for(auto [v,i]:g[u])
                if(bel[u]!=bel[v]) {
                    forest[bel[u]].emplace_back(bel[v], i/2);
                }
        return forest;
    }
};

struct Maxcnt {
    int mx;
    vector<int> f,g;

    void add(int x) {
        g[f[x]]--;
        f[x]++;
        g[f[x]]++;
        mx=max(mx,f[x]);
    }

    void del(int x) {
        g[f[x]]--;
        f[x]--;
        g[f[x]]++;
        if(!g[mx]) mx--;
    }

    Maxcnt(): mx(0),f(vector<int>(N)),g(vector<int>(N)) {
        f[0]=N;
        g[0]=N;
    }
};

namespace dsu {
    int id[N],ed[N],ori[N],sz[N],hch[N],idx;
    vector<vector<pair<int,int>>> adj;
    vector<vector<int>> w;

    int res[N]; //res[i]=i号边所在森林切去i边增加的值
    vector<int> curid,curw;
    bool vis[N];
    Maxcnt up,dn;

    void init(int u,int fa) {
        vis[u]=1;
        sz[u]=1;
        id[u]=++idx;
        ori[id[u]]=u;
        for(auto [v,id]:adj[u]) {
            if(v!=fa) {
                init(v,u);
                if(sz[v]>sz[hch[u]]) hch[u]=v;
                sz[u]+=sz[v];
                curid.emplace_back(id);
            }
        }
        for(int x:w[u]) curw.emplace_back(x);
        ed[u]=idx;
    }

    void solve(int u,int fa,bool keep,int eid) {
        auto add=[](int id) {
            int x=ori[id];
            for(int v:w[x]) {
                dn.add(v);
                up.del(v);
            }
        };

        auto del=[](int id) {
            int x=ori[id];
            for(int v:w[x]) {
                up.add(v);
                dn.del(v);
            }
        };
        
        int hchid=0;
        for(auto [v,id]:adj[u]) {
            if(v!=fa) {
                if(v!=hch[u]) solve(v,u,0,id);
                else hchid=id;
            }
        }
        if(hch[u]) solve(hch[u],u,1,hchid);
        for(auto [v,_]:adj[u])
            if(v!=fa&&v!=hch[u]) 
                for(int i=id[v];i<=ed[v];i++) add(i);
        add(id[u]);
        
        if(eid!=-1) res[eid]=up.mx+dn.mx;

        if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
    }

    int sum;
    void solve(int u) {
        if(vis[u]) return;
        init(u, -1);
        for(int x:curw) up.add(x);
        int mx=up.mx;

        sum+=mx;
        solve(u,-1,0,-1);
        for(int id:curid) res[id]-=mx;

        for(int x:curw) up.del(x);
        curid.clear();
        curw.clear();
    }

    void clear(int n=N-1) {
        idx=0;
        sum=0;
        fill(hch,hch+n+1,0);
        fill(vis,vis+n+1,0);
        fill(res,res+n+1,0);
        adj.clear();
        w.clear();
    }
}

void solve() {
    int n,m;
    io>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        io>>a[i];
    }

    Tarjan tar(n,a);
    for(int i=0; i<m; ++i) {
        int u,v;
        io>>u>>v;
        --u,--v;
        tar.addEdge(u,v);    
    }
    tar.converge();
    dsu::adj=std::move(tar.newForest());
    dsu::w=std::move(tar.ecc);

    for(int i=0;i<dsu::adj.size();i++) dsu::solve(i);
    for(int i=0;i<m;i++) io<<dsu::sum+dsu::res[i]<<" \n"[i==m-1];

    dsu::clear(max(n,m));
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    io>>t;
    while(t--) solve();
    return 0;
}