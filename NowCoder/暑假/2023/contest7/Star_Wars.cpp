#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10,mod=1<<30;
map<pair<int,int>,int> cnt;
vector<int> adj[N];
LL sum[N],val[N];

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

void solve() {
    int n,q;
    io>>n>>q;
    LL ans=0;
    while(q--) {
        int op,x,y;
        io>>op>>x;
        if(op<=3) io>>y;
        x^=ans%mod;
        y^=ans%mod;

        if(op==1) {
            if(x>y) swap(x,y);
            if(++cnt[{x,y}]==1) {
                if(adj[x].size()>adj[y].size()) swap(x,y);
                adj[x].emplace_back(y);
                sum[y]+=val[x];
            }
        }
        else if(op==2) {
            if(x>y) swap(x,y);
            if(--cnt[{x,y}]==0) {
                auto it=find(adj[x].begin(),adj[x].end(),y);
                if(it!=adj[x].end()) {
                    swap(*it,adj[x].back());
                    adj[x].pop_back();
                    sum[y]-=val[x];
                }
                it=find(adj[y].begin(),adj[y].end(),x);
                if(it!=adj[y].end()) {
                    swap(*it,adj[y].back());
                    adj[y].pop_back();
                    sum[x]-=val[y];
                }
            }
        }
        else if(op==3) {
            val[x]+=y;
            for(int v:adj[x]) sum[v]+=y;
        }
        else {
            ans=sum[x]+val[x];
            for(int v:adj[x]) ans+=val[v];
            io<<ans<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}