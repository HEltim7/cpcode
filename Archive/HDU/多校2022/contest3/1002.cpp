#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10,M=20;
int n;
int tim[M],len[M];
int sttime[1<<M];
LL H;
LL pre[M][N];
LL dp[1<<M];
vector<int> st[M];

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

int caltime(int x) {
    int res=0;
    for(int i=0;i<n;i++)
        if(x&(1<<i)) res+=tim[i];
    return res;
}

bool check(int mid) {
    memset(dp, 0, sizeof(LL)*(1<<n));
    for(int i=0;i<n;i++) {
        for(auto x:st[i]) {
            int cur=mid-sttime[x];
            if(cur<=0) continue;
            for(int j=0;j<n;j++) {
                if(!(x&(1<<j))) {
                    dp[x+(1<<j)]=max(dp[x+(1<<j)],dp[x]+pre[j][min(cur,len[j])]);
                    if(dp[x+(1<<j)]>=H) return 1;
                }
            }
        }
    }
    return 0;
}

void solve() {
    read(n),read(H);
    LL sum=0;
    int l=1,r=0;
    for(int i=0;i<n;i++) {
        read(tim[i]),read(len[i]);
        r+=max(tim[i],len[i]);
        for(int j=1;j<=len[i];j++) {
            read(pre[i][j]);
            pre[i][j]+=pre[i][j-1];
        }
        sum+=pre[i][len[i]];
    }
    if(sum<H) {
        write("-1\n");
        return;
    }
    for(int i=0;i<=n;i++) st[i].clear();
    for(int i=0;i<(1<<n);i++) st[__builtin_popcount(i)].push_back(i);
    for(int i=0;i<(1<<n);i++) sttime[i]=caltime(i);
    
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    write(l-1),write('\n');
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}