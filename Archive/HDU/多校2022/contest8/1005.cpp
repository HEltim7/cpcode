#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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

using LL=long long;
using VI=vector<int>;
constexpr int N=2e5+10;

int a[N],b[N],L[N],R[N],n;
bool st[N],mark[N];
int primes[N],minp[N],idx;
VI key[N];

void init(int n) {
    st[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!st[i]) primes[idx++]=i,minp[i]=i;
        for(int j=0;primes[j]<=n/i;j++) {
            st[primes[j]*i]=true;
            minp[primes[j]*i]=primes[j];
            if(i%primes[j]==0) break;
        }
    }
}

bool extend_r(int &l,int &r) {
    if(r==n) return 0;
    auto it=lower_bound(key[b[r]].begin(),key[b[r]].end(),l);
    if(it!=key[b[r]].end()&&*it<=r) {
        l=min(l,L[r+1]);
        r=R[r+1];
        return 1;
    }
    return 0;     
}

bool extend_l(int &l,int &r) {
    if(l==1) return 0;
    auto it=lower_bound(key[b[l-1]].begin(),key[b[l-1]].end(),l);
    if(it!=key[b[l-1]].end()&&*it<=r) {
        r=max(r,R[l-1]);
        l=L[l-1];
        return 1;
    }
    return 0;
}

void solve() {
    int m;
    reads(n,m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i< n;i++) mark[read(b[i])]=1;
    for(int i=1;i<=n;i++) {
        int t=a[i],pre=-1;
        while(t>1) {
            if(minp[t]!=pre&&mark[minp[t]]) key[minp[t]].push_back(i);
            pre=minp[t];
            t/=minp[t];
        }
    }
    for(int i=1;i<=n;i++) sort(key[i].begin(),key[i].end());

    for(int i=1;i<=n;i++) L[i]=R[i]=i;
    for(int i=n-1;i>=1;i--) 
        while(extend_r(L[i],R[i])) ;
    for(int i=2;i<=n;i++)
        while(extend_l(L[i], R[i])||extend_r(L[i], R[i])) ;
        
    for(int i=1;i<n;i++) mark[b[i]]=0,key[b[i]].clear();
    
    while(m--) {
        int x,y;
        reads(x,y);
        if(y>=L[x]&&y<=R[x]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main() {
    init(N-10);
    int t=read(t);
    while(t--) solve();
    return 0;
}