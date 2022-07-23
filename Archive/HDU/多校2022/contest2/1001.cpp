#pragma GCC optimize("Ofast")
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;

using LL=long long;
using PII=pair<int,int>;
using VII=vector<PII>;
const int N=2e5+10,M=N;
int h[N],e[M],ne[M],idx;
int id[N],cnt;
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

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int fa,int d){
    dep[x]=d,p[x]=fa,sz[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        dfs1(j,x,d+1);
        sz[x]+=sz[j];
        if(sz[hch[x]]<sz[j]) hch[x]=j;
    }
}

void dfs2(int x,int t){
    assert(t>0);
    id[x]=++cnt,top[x]=t;
    if(!hch[x]) return;
    dfs2(hch[x],t);
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(j==p[x]||j==hch[x]) continue;
        dfs2(j,j);
    }
}

void get_path(VII &res,int x,int y){
    while(top[x]!=top[y]){
        assert(top[x]>0&&top[y]>0);
        assert(x!=-1);
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res.emplace_back(id[top[x]],id[x]);
        x=p[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y);
    res.emplace_back(id[y],id[x]);
}

void get_tree(VII &res,int x){
    res.emplace_back(id[x],id[x]+sz[x]-1);
}

void merge(VII &seg) {
    sort(seg.begin(),seg.end());
    VII res(1,seg.front());
    for(int i=1;i<seg.size();i++) {
        int x=seg[i].first,y=seg[i].second;
        if(x>res.back().second) res.push_back(seg[i]);
        else res.back().second=max(res.back().second,y);
    }
    seg=res;
}

VII inter(VII &a,VII &b) {
    VII res;
    int l=0,r=0,idx=-1;
    while(l<a.size()&&r<b.size()) {
        auto pre=a[l],suf=b[r];
        if(pre.first>suf.first) swap(pre,suf);
        if(pre.second<suf.first) ;
        else if(pre.second<=suf.second) 
            res.emplace_back(suf.first,pre.second);
        else res.emplace_back(suf.first,suf.second);
        idx=min(pre.second,suf.second);
        if(a[l].second<=idx) l++;
        if(b[r].second<=idx) r++;
    }
    return res;
}

void solve() {
    int n=read(n),q=read(q);
    memset(h, -1, sizeof(int)*(n+1));
    memset(hch, 0, sizeof(int)*(n+1));
    idx=cnt=0;
    for(int i=1;i<n;i++) {
        int r=read(r);
        add(r,i+1);
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++) assert(top[i]>0);
    while(q--) {
        VII seg[3],res;
        int in;
        int sz[]={read(in),read(in),read(in)};
        for(int i=0;i<3;i++) {
            for(int j=0;j<sz[i];j++) {
                if(i<2) get_path(seg[i], 1, read(in));
                else get_tree(seg[i], read(in));
            }
            merge(seg[i]);
        }
        res=inter(seg[0], seg[1]);
        res=inter(res, seg[2]);
        int ans=0;
        for(int i=0;i<res.size();i++) ans+=res[i].second-res[i].first+1;
        write(ans),write('\n');
    }
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}