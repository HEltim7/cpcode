#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
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

using LL=long long;
const int LCM=79205,INF=1e9;
int dp[LCM];

void init() {
    dp[0]=0;
    for(int i=1;i<LCM;i++) {
        dp[i]=INF;
        if(i-7>=0) dp[i]=min(dp[i],dp[i-7]+1);
        if(i-31>=0) dp[i]=min(dp[i],dp[i-31]+1);
        if(i-365>=0) dp[i]=min(dp[i],dp[i-365]+1);
    }
}

void solve() {
    LL n=read(n);
    LL ans=1LL*n/LCM*(31*7);
    n%=LCM;
    if(dp[n]==INF) write("-1\n");
    else write(ans+dp[n]),write('\n');
}

int main() {
    init();
    int t=read(t);
    while(t--) solve();
    return 0;
}