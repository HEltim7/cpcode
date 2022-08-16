#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

using LL=long long;
constexpr int N=1e5+10;
int arr[N],ans[N],len;
deque<int> pre,suf;

int getid(int x) {
    return x/len;
}

struct Query {
    int l,r,id,bid;
    bool operator<(const Query &x) {
        if(bid==x.bid) return r<x.r;
        return bid<x.bid;
    }
    void init() { bid=getid(l); }
} q[N];

void add_l(int x) {
    while(pre.size()&&x>pre.front()) pre.pop_front();
    pre.push_front(x);
}

void solve() {
    int n=read(n),m=read(m);
    len=sqrt(n)+1;
    for(int i=1;i<=n;i++) read(arr[i]);
    for(int i=1;i<=m;i++) reads(q[i].l,q[i].r),q[i].id=i,q[i].init();
    sort(q+1,q+1+m);
    
    for(int i=1,r=0,mid=0;i<=m;i++) {
        int L=q[i].l,R=q[i].r;
        pre.clear();
        if(i==1||q[i].bid!=q[i-1].bid) {
            suf.clear();
            mid=getid(L)*len+len-1;
            r=mid+1;
        }
        if(getid(L)==getid(R)) {
            for(int j=R-1;j>=L;j--) if(arr[j]>arr[j+1]) add_l(arr[j]);
            ans[q[i].id]=pre.size();
        }
        else {
            if(arr[mid]>arr[mid+1]) pre.push_front(arr[mid]);
            for(int j=mid-1;j>=L;j--) if(arr[j]>arr[j+1]) add_l(arr[j]);
            for(;r<R;r++) if(arr[r]>arr[r+1]&&(suf.empty()||arr[r]>=suf.back())) suf.push_back(arr[r]);
            
            ans[q[i].id]=pre.size()+suf.size();
            debug(i,mid,L,R,q[i].id,ans[q[i].id]);
            debug(pre);
            debug(suf);
            if(pre.size()&&suf.size()&&pre.back()>suf.front()) {
                auto x=lower_bound(suf.begin(),suf.end(),pre.back())-suf.begin();
                ans[q[i].id]-=x;
            }
        }
    }
    for(int i=1;i<=m;i++) writes(ans[i],'\n');
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt","w",stdout);
#endif
    int t=read(t);
    while(t--) solve();
    return 0;
}