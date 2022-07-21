// #pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;

using LL=long long;
const int N=2e5,M=N;
int h[N],w[N],e[M],ne[M],idx;
int id[N],nw[N],cnt;
int dep[N],sz[N],top[N],p[N],hch[N];

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


struct Node{
    int l,r;
    int sum;
} tr[N*4];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void modify(int x,int l,int r,int v){
    
}

int query(int x,int l,int r){
    
}

void dfs1(int x,int fa,int d){
    dep[x]=d,p[x]=fa,sz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,x,d+1);
        sz[x]+=sz[j];
        if(sz[hch[x]]<sz[j]) hch[x]=j;
    }
}

void dfs2(int x,int t){
    id[x]=++cnt,nw[cnt]=w[x],top[x]=t;
    if(!hch[x]) return;
    dfs2(hch[x],t);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==p[x]||j==hch[x]) continue;
        dfs2(j,j);
    }
}

void modify_path(int x,int y,int k){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        modify(1,id[top[x]],id[x],k);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    modify(1,id[y],id[x],k);
}

int query_path(int x,int y){
    int res=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res+=query(1,id[top[x]],id[x]);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    res+=query(1,id[y],id[x]);
    return res;
}

void modify_tree(int x,int k){
    modify(1,id[x],id[x]+sz[x]-1,k);
}

int query_tree(int x){
    return query(1,id[x],id[x]+sz[x]-1);
}

void solve() {
    int n=read(n),q=read(q);
    memset(h, -1, sizeof(int)*(n+1));
    idx=0;
    for(int i=1;i<n;i++) {
        int r=read(r);
        add(r,i+1);
    }
    while(q--) {
        int A=read(A),B=read(B),C=read(C),in;
        for(int i=1;i<=A;i++) {}
    }
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}