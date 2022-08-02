#pragma GCC optimize("Ofast")
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
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
const int N=2e5+10;
int n,m;

multimap<LL, int> timp; //最近更新时间为x的队列集合
set<int> num; //队列人数集合
set<int> ids[N]; //人数为x的队列集合
LL ans;
pair<LL,LL> customer[N];

struct Que {
    queue<LL> q;
    LL end=0;
    int id;

    void pop() {
        int st=size();
        ids[st].erase(id);
        if(ids[st].size()==0) num.erase(st);
        st--;
        ids[st].insert(id);
        if(ids[st].size()==1) num.insert(st);

        q.pop();
        timp.erase(timp.begin());
        if(q.size()) timp.emplace(q.front(),id);
    }

    void push(int pid) {
        int st=size();
        ids[st].erase(id);
        if(ids[st].size()==0) num.erase(st);
        end=max(end,customer[pid].first)+customer[pid].second;
        ans=max(ans,end);
        q.push(end);

        st++;
        ids[st].insert(id);
        if(ids[st].size()==1) num.insert(st);

        if(size()==1) { timp.emplace(q.front(),id); }
    }

    void clear() {
        while(q.size()) q.pop();
        end=0;
    }
    
    int size() { return q.size(); }

} que[N];

void init() {
    ans=0;
    timp.clear();
    num.clear();
    num.insert(0);
    for(int i=0;i<=n;i++) ids[i].clear();
    for(int i=1;i<=m;i++) ids[0].insert(i);
    for(int i=1;i<=m;i++) que[i].clear();
    for(int i=1;i<=m;i++) que[i].id=i;
}

void solve() {
    reads(n,m);
    init();
    for(int i=1;i<=n;i++) reads(customer[i].first,customer[i].second);
    sort(customer+1,customer+1+n);
    for(int i=1;i<=n;i++) {
        while(timp.size()&&timp.begin()->first<=customer[i].first) 
            que[timp.begin()->second].pop();
        int st=*num.begin();
        int qid=*ids[st].begin();
        que[qid].push(i);
    }
    writes(ans,'\n');
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}