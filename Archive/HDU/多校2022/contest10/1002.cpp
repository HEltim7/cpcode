#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
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
    T inv() const {
        T res=1,a=v,b=mod-2;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }

    Modint &operator+=(const Modint &x) { v+=x.v; if(v>=mod) v-=mod; return *this; }
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
using Mint=Modint<>;

using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10,mod=998244353;
int val[N],pos[N];
int row[N],col[N];
Mint dp[N];
PII tmp[N];

LL qpow(LL a,LL b) {
    LL res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

[[maybe_unused]] Mint f(int x) {
    return 0;
}

[[maybe_unused]] Mint g(int x) {
    return 0;
}

void solve() {
    int n,m;
    reads(n,m);
    for(int i=1;i<=m;i++) {
        reads(tmp[i].first,tmp[i].second);
        if(tmp[i].first>tmp[i].second) swap(tmp[i].first,tmp[i].second);
    }
    sort(tmp+1,tmp+m+1,[](PII &a,PII &b){
        if (a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    });
    for(int i=1;i<=m;i++) {
        row[i]=tmp[i].first;
        col[i]=tmp[i].second;
        val[i]=col[i]-row[i]+1;
    }
    vector<int> stk;

    for(int i=1;i<=m;i++) {
        debug(i);
        if(stk.size()&&col[i]==col[stk.back()]) continue;
        while(stk.size()&&val[i]>=col[i]-row[stk.back()]+1) stk.pop_back();
        if(stk.size()) {
            int t=stk.back();
            int len=col[i]-row[t]-val[i];
            dp[i]=dp[t]*g(len);
        }
        else {
            dp[i]=f(col[i]-val[i]);
            debug(i,dp[i]);
        }
        stk.push_back(i);
    }
    Mint ans=dp[stk.back()]*f(n-col[stk.back()]);
    cout<<ans<<endl;
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}