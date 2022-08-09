#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
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

template<typename T=long long,T mod=998244353> struct Modint {
    T v;
    T inv() {
        T res=1,a=v,b=mod-2;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }

    Modint &operator+=(const Modint &x) { v+=x.v; if(v>mod) v-=mod; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; if(v<0) v+=mod; return *this; }
    Modint &operator*=(const Modint &x) { v=v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(T x=0): v((x%=mod)<0?x+mod:x) {}
};

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

using Mod=Modint<>;
using LL=long long;
const int N=5e5+10,mod=998244353-1;
vector<int> adj[N];
Mod dp[N][4],ans;

Mod fn(vector<Mod> a,vector<Mod> b,vector<Mod> c) {
    Mod res=0;
    for(int i=1;i<a.size();i++) a[i]+=a[i-1];
    for(int i=1;i<b.size();i++) b[i]*=a[i-1];
    for(int i=2;i<b.size();i++) b[i]+=b[i-1];
    for(int i=2;i<c.size();i++) res+=c[i]*b[i-1];
    assert(res>=0&&res<=mod);
    return res;
}

void clear(int u) {
    dp[u][1]=dp[u][2]=dp[u][3]=0;
}

void dfs(int u,int fa,int deep) {
    if(deep>3) return;
    debug(u);
    vector<Mod> leg,body;
    for(int v:adj[u]) {
        if(v==fa) continue;
        dfs(v,u,deep++);
        dp[u][1]++;
        ans+=dp[v][3];
        leg.push_back(dp[v][1]);
        body.push_back(dp[v][2]);
    }
    LL t=dp[u][1].v*(dp[u][1].v-1)/2;
    if(dp[u][1]>0) dp[u][2]=t;
    dp[u][3]+=fn(body,leg,leg);
    dp[u][3]+=fn(leg,body,leg);
    dp[u][3]+=fn(leg,leg,body);
    for(int v:adj[u]) if(v!=fa) clear(v);
    assert(dp[u][1]>=0&&dp[u][2]>=0&&dp[u][3]>=0&&dp[u][1]<=mod&&dp[u][2]<=mod&&dp[u][3]<=mod);
    debug(u,dp[u][1].v,dp[u][2].v,dp[2][3].v);
}

void solve() {
    int n=read(n);
    for(int i=1;i<=n;i++) adj[i].clear(),clear(i);
    ans=0;
    for(int i=1;i<n;i++) {
        int u,v;
        reads(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) dfs(i,-1,0),clear(i);
    assert(ans>=0);
    cout<<ans<<endl;
}

int main() {
    // freopen("in.txt","r",stdin);
    int t=read(t);
    while(t--) solve();
    return 0;
}