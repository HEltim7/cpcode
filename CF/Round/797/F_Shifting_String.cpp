#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=210;
char s[2][N],init[N];
int p[N];
bool st[N];

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

    template<typename... T> void reads_impl(T&... x) { (rd(x),...); }

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

    template<typename... T> void writes_impl(const T&... x) { (wt(x),...); }

    #define write(...) io::wt(__VA_ARGS__)
    #define writes(...) io::writes_impl(__VA_ARGS__)

    struct Exit {
        ~Exit() { clear_buffer(); }
    } static exit;
}

void shift(int cur,vector<int> &v) {
    for(auto i:v)
        s[cur][i]=s[!cur][p[i]];
}

bool check(int cur,vector<int> &v) {
    for(auto i:v)
        if(s[cur][i]!=init[i]) return 1;
    return 0;
}

LL dfs(int idx) {
    vector<int> v;
    int t=p[idx];
    v.push_back(idx);
    st[idx]=1;
    while(idx!=t) v.push_back(t),t=p[t],st[t]=1;
    
    int cur=0,ans=0;
    do {
        cur^=1;
        shift(cur,v);
        ans++;
    } while (check(cur,v));
    return ans;
}

void solve() {
    int n=read(n);
    memset(st,0,sizeof (bool)*(n+1));
    for(int i=1;i<=n;i++) init[i]=read(s[0][i]);
    for(int i=1;i<=n;i++) read(p[i]);
    LL ans=1;
    for(int i=1;i<=n;i++) if(!st[i]) ans=lcm(ans,dfs(i));
    writes(ans,'\n');
}

int main() {
    // freopen64("in.txt","r",stdin);
    // freopen64("out.txt","w",stdout);
    int t=read(t);
    while(t--) solve();
    return 0;
}