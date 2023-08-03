#include <functional>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<tuple>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ld eps=1e-8;
const int INF=0x3f3f3f3f,mod=998244353;

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

const int N=100005;
int p[N];
int n;
int tr[N];
int res[N];
int lowbit(int x)
{
    return x&-x;
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res+=tr[x];
        x-=lowbit(x);
    }
    return res;
}
void add(int x,int c)
{
    while(x<N)
    {
        tr[x]+=c;
        x+=lowbit(x);
    }
    return ;
}

vector<int> vec[N];
vector<pair<int,int>> qry[N];

void solve()
{
    memset(tr,0,sizeof tr);
    io>>n;

    for(int i=1;i<=n;i++) vec[i].clear(),qry[i].clear();

    vector<int> pos(n+1);
    for(int i=1;i<=n;i++) pos[read(p[i])]=i;
    for(int i=1;i<=2*n/i;i++)//枚举平方数
    {
        for(int j=1;j<i*i-j;j++)
        {
            int k=i*i-j;
            if(j<=n&&k<=n)
            {
                int l=min(pos[j],pos[k]);
                int r=max(pos[j],pos[k]);
                vec[r].emplace_back(l);
            }
        }
    }
    int Q=read(Q);
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        io>>l>>r;
        qry[r].emplace_back(l,i);
    }

    int cnt=0;
    for(int i=1;i<=n;i++) {
        for(int l:vec[i]) {
            add(l, 1);
            cnt++;
        }
        for(auto [l,id]:qry[i]) {
            res[id]=cnt-query(l-1);
        }
    }
    for(int i=1;i<=Q;i++) io<<res[i]<<'\n';
}
int main()
{
    int T=read(T);
    while(T--)
    {
        solve();
    }
}