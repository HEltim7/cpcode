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

constexpr int INF=1e9+10;
constexpr int N=1e6+10;
int arr[N],ed[N];
LL cost[N];

void solve() {
    int n,m;
    LL k;
    io>>n>>m>>k;
    
    for(int i=1;i<=n;i++) io>>arr[i];
    for(int i=1;i<=m;i++) io>>cost[i];
    sort(arr+1,arr+1+n);

    cost[1]=0;
    cost[m+1]=INF;

    for(int i=m;i>=1;i--) cost[i]=min(cost[i+1],cost[i]);
    for(int i=3,t=2;i<=m+1;i++) {
        if(t*t<i) t++;
        for(int l=2;l<=t;l++) {
            cost[i]=min(cost[i],cost[l]+cost[(i+l-1)/l]);
        }
    }
    for(int i=m;i>=1;i--) cost[i]=min(cost[i+1],cost[i]);
    debug(cost,1,m+1);

    auto check=[&](int mid) {
        LL sum=0;
        for(int i=1;i<=(n+1)/2;i++) {
            if(arr[i]<=mid) continue;
            int t;
            if(mid==0) t=arr[i]+1;
            else t=(arr[i]+mid-1)/mid;
            sum+=cost[t];
            if(sum>k) return false;
        }
        return true;
    };

    int l=0,r=m;
    while(l<r) {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }

    io<<l<<endl;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    int t;
    io>>t;
    while(t--) solve();
    return 0;
}