#pragma GCC optimize("Ofast")
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef pair<int,int> pii;
typedef long long ll;
const double eps=1e-8;
const int INF=0x3f3f3f3f;

#ifndef ONLINE_JUDGE
#define debug(...)
#include<debug>
#else
#define debug(...)
#endif

const int N=2000006;
string s[N];
namespace io {
    const int MAXBUF = 1e6, MAXLEN = 2e7+10;
    char buf[MAXBUF], *pl, *pr;
    char str[MAXLEN];

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T>
    inline T rd(T &x) {
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

    inline char* rd(char *p = str){
        char c = gc(), *h = p;
        while (!isgraph(c)) c = gc();
        while (isgraph(c)) *p++ = c, c = gc();
        *p = '\0';
        return h;
    }

    inline char rd(char &c) {
        c = gc();
        while(!isgraph(c)) c = gc();
        return c;
    }

    inline string rd(string &s) { return s = rd(str); }

    template<typename T> void reads_impl(T &x) { rd(x); }
    template<typename T,typename... U> void
    reads_impl(T &x, U&... vars) { rd(x);reads_impl(vars...); }

    #define read(x) io::rd(x)
    #define reads(...) io::reads_impl(__VA_ARGS__)

    const int MAXPBUF = 1e6, PRECISION = 7;
    char pbuf[MAXPBUF], *pp = pbuf;

    inline void push(const char &c) {
        if (pp - pbuf == MAXPBUF) fwrite(pbuf, 1, pp-pbuf, stdout), pp = pbuf;
        *pp++ = c;
    }

    template<typename T>
    inline void wt(T x) {
        if (x < 0) push('-'), x = -x;
        static int sta[40];
        int top = 0;
        do {
            sta[top++] = x % 10;
        } while (x/=10);
        while (top) push(sta[--top] + '0');
    }

    template<typename T>
    inline void wt_f(T x,int p) {
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

    inline void wt(const char &c) { push(c); }
    inline void wt(const string &s) { for (auto &x:s) push(x); }
    inline void wt(const char *p) { while (*p != '\0') push(*p++); }

    inline void wt(const float &x, int p = PRECISION) { wt_f(x,p); }
    inline void wt(const double &x, int p = PRECISION) { wt_f(x,p); }
    inline void wt(const long double &x, int p = PRECISION) { wt_f(x,p); }
    
    template<typename T> void writes_impl(const T &x) { wt(x); }
    template<typename T, typename... U> void
    writes_impl(const T &x, const U&... vars) { wt(x);writes_impl(vars...); }

    #define write(...) io::wt(__VA_ARGS__)
    #define writes(...) io::writes_impl(__VA_ARGS__)

    struct Exit {
        ~Exit() { fwrite(pbuf, 1, pp-pbuf, stdout); }
    } static exit;
}
bool cmp(string &q,string &w)
{
    return q+w<w+q;
}
int main()
{
    int n;
    read(n);
    for(int i=1;i<=n;i++)
    {
        read(s[i]);
    }

    sort(s+1,s+n+1,cmp);

    for(int i=1;i<=n;i++)
    {
        write(s[i]);
    }
}
