#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
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

using LL=long long;
using PII=pair<int,int>;
constexpr int N=5e4+10,M=500;

vector<PII> edge[N];
int vx[N],vy[N],fa[N];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void solve() {
    LL ans=0;
    int idx=0;
    int n=read(n);
    int len=sqrt(n-1);

    for(int i=1;i<=n;i++) edge[i].clear();
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) read(vy[i]);
    for(int i=1;i<=n;i++) vx[vy[i]]=i;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=min(i+len,n);j++) {
            int val=(j-i)*abs(vy[j]-vy[i]);
            if(val<=n-1) edge[val].emplace_back(i,j);
        }
        for(int j=vy[i]+1;j<=min(vy[i]+len,n);j++) {
            int val=(j-vy[i])*abs(vx[j]-i);
            if(val<=n-1&&(vx[j]<i-len||vx[j]>i+len)) edge[val].emplace_back(i,vx[j]);
        }
    }

    for(int i=1,cnt=0;i<n;i++) {
        for(int j=0;j<edge[i].size();j++) {
            int a=findfa(edge[i][j].first);
            int b=findfa(edge[i][j].second);
            if(a==b) continue;
            fa[b]=a;
            cnt++;
            ans+=i;
        }
    }
    writes(ans,'\n');
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}