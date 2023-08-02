#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=2e4+10,M=2e3+10,INF=4e8;
vector<int> pre[N];

namespace fast_io {
    constexpr int MAXBUF = 1e6;
    char buf[MAXBUF], *pl, *pr;

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
        return x = x * f;
    }

    template<typename... T> auto read(T&... x) { return (rd(x),...); }   
    #undef gc

    struct IO {
        template<typename T> friend IO&
        operator>>(IO &io, T& x) { rd(x); return io; }
    } static io;
}
using fast_io::read,fast_io::io;

void solve() {
    int n,m;
    io>>n>>m;
    
    int ans=INF;
    pre[0].resize(m+3);
    for(int i=1;i<=n;i++) {
        pre[i].resize(m+3);
        int in;
        io>>in;
        int k=max(0,i-m);
        pre[i][0]=INF;
        for(int j=1;j<=i-max(0,i-m+1);j++) {
            int cur=pre[i-j][i-j-k]+in;
            pre[i][j]=min(cur,pre[i][j-1]);
            if(i-j>=n-m+1) ans=min(ans,cur);
        }

        if(i-m-1>=0) {
            pre[i-m-1].clear();
            pre[i-m-1].shrink_to_fit();
        }
    }

    printf("%d\n",ans);
}

int main() {
    int t;
    io>>t;
    while(t--) solve();
    return 0;
}