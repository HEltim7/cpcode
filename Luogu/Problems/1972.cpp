#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

using LL=long long;
using TIII=tuple<int,int,int>;
constexpr int N=1e6+10;
int arr[N],ans[N],pos[N];
TIII q[N];

namespace io {
    constexpr int MAXBUF = 1e6, MAXLEN = 1e6;
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

    template<typename... T> auto read_impl(T&... x) { return (rd(x),...); }

    #undef gc
    #define read(...) io::read_impl(__VA_ARGS__)

    constexpr int MAXPBUF = 1e6, PRECISION = 7;
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

    template<typename... T> void write_impl(const T&... x) { (wt(x),...); }

    #define writef(x,p) io::wt_f(x,p)
    #define write(...) io::write_impl(__VA_ARGS__)

    struct Exit {
        ~Exit() { clear_buffer(); }
    } static exit;
}

template<typename T=int> 
struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,T &val) {
        aim+=val;
    }

    void add(int pos,T val) {
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};

void solve() {
    int n=read(n);
    for(int i=1;i<=n;i++) read(arr[i]);
    int m=read(m);
    for(int i=1;i<=m;i++) {
        int l,r;
        read(l,r);
        q[i]={r,l,i};
    }
    sort(q+1,q+1+m);

    Fenwick<> tr(n+10);
    auto extend=[&](int x) {
        int c=arr[x];
        if(pos[c]) tr.add(pos[c], -1);
        pos[c]=x;
        tr.add(x, 1);
    };
    
    for(int i=1,R=0;i<=m;i++) {
        auto [r,l,id]=q[i];
        while(R<r) extend(++R);
        ans[id]=tr.query(r)-tr.query(l-1);
    }
    for(int i=1;i<=m;i++) write(ans[i],'\n');
}

int main() {
    solve();
    return 0;
}