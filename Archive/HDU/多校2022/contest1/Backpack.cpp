#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

using LL=long long;
const int N=1<<10,M=N+10;
int v[M],w[M];
bitset<N> dp[2][M];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

namespace io {
    const int MAXBUF = 1e5;
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

    // template<typename... T> void reads_impl(T&... x) { (rd(x),...); }

    #define read(x) io::rd(x)
    // #define reads(...) io::reads_impl(__VA_ARGS__)
}

void solve() {
    int n=read(n),m=read(m);
    for(int i=1;i<=n;i++) read(v[i]),read(w[i]);
    for(int i=0;i<N;i++) dp[0][i].reset();
    dp[0][0][0]=1;
    for(int i=1,t=i&1;i<=n;i++,t=i&1)
        for(int j=0;j<N;j++)
            dp[t][j]=dp[!t][j^w[i]]<<v[i]|dp[!t][j];
    int ans=-1;
    for(int i=1;i<N;i++) if(dp[n&1][i][m]) ans=max(ans,i);
    printf("%d\n",ans);
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}