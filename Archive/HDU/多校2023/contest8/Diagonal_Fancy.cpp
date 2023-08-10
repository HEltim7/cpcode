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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
int arr[N][N],last[N*N];
using Arr=array<int,N>;
using Mat=array<Arr,N>;
Mat maxr,maxc,slash;

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

template<int size,typename T> struct SparseTable {
    constexpr static int M=__lg(size)+1;
    T st[M][size];
    
    T merge(const T &x,const T &y) {
        return min(x,y);
    }

    void build(int n,const Arr &arr) {
        for(int i=1;i<=n;i++) st[0][i]=arr[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=merge(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return merge(st[k][l],st[k][r-(1<<k)+1]);
    }
};

SparseTable<N, short> str[N];
SparseTable<N, short> stc[N];
SparseTable<N, short> sts[N*2];

void solve() {
    int n,m;
    io>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int in;
            io>>in;
            arr[i*2-1][j*2-1]=arr[i*2][j*2]=in;
            arr[i*2-1][j*2]=arr[i*2][j*2-1]=0;
        }
    }
    n*=2,m*=2;
    // for(int i=1;i<=n;i++) debug(arr[i],1,m);

    for(int i=n;i>=1;i--) {
        for(int j=m;j>=1;j--) {
            if(i+1<=n&&j+1<=m) {
                if(arr[i][j]==arr[i+1][j+1]) {
                    maxr[j][i]=maxr[j+1][i+1];
                    maxc[i][j]=maxc[i+1][j+1];
                }
                else {
                    maxr[j][i]=i+1;
                    maxc[i][j]=j+1;
                }
            }
            else maxr[j][i]=n+1,maxc[i][j]=m+1;
        }
    }

    for(int j=1;j<=m;j+=2) str[j].build(n, maxr[j]);
    for(int i=1;i<=n;i+=2) stc[i].build(m, maxc[i]);

    auto get_id=[&](int r,int c) {
        return r+c-1;
    };

    vector<pair<int,int>> start;
    for(int i=1;i<=n;i+=2) start.emplace_back(i,1);
    for(int i=2;i<=m;i+=2) start.emplace_back(n,i);
    for(auto [r,c]:start) {
        int idx=get_id(r, c);
        int i=r,j=c;
        while(i>=1&&j<=m) {
            if(!last[arr[i][j]]) slash[idx][i]=n+1;
            else slash[idx][i]=last[arr[i][j]];
            last[arr[i][j]]=i;
            i--,j++;
        }
        i=r,j=c;
        while(i>=1&&j<=m) {
            last[arr[i][j]]=0;
            i--,j++;
        }
        
        sts[idx].build(r, slash[idx]);
    }

    LL ans=0;
    for(int i=1;i<=n;i+=2) {
        for(int j=1;j<=m;j+=2) {
            int l=1,r=min(n-i,m-j);
            while(l<r) {
                int mid=(l+r+1)/2;
                int t=(mid&1)?i+mid-1:i+mid;
                if(
                    str[j].query(i, i+mid)<=i+mid||
                    stc[i].query(j, j+mid)<=j+mid||
                    sts[get_id(t, j)].query(i, t)<=t
                ) r=mid-1;
                else l=mid;
            }
            ans+=(l+1)/2;
        }
    }

    io<<ans<<endl;
}

int main() {
    int t;
    io>>t;
    while(t--) solve();
    return 0;
}