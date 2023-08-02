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
constexpr int N=3e5;
constexpr LL INF=2e6;
int arr[N];

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

template<typename T> T mylcm(T x,T y) {
    return x>=INF||y>=INF?INF:min(lcm(x,y),T(INF));
}

template<int size,typename T=int> struct SparseTable {
    constexpr static int M=__lg(size);
    T st[M][size];

    void build(int n) {
        for(int i=1;i<=n;i++) st[0][i]=arr[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=mylcm(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return mylcm(st[k][l],st[k][r-(1<<k)+1]);
    }
};
SparseTable<N,LL> st;

void solve() {
    int n;
    io>>n;
    for(int i=1;i<=n;i++) io>>arr[i];
    st.build(n);
    
    vector<int> res;
    for(int i=1;i<=n;i++) {
        int cur=arr[i];
        while(cur<INF) {
            res.emplace_back(cur);
            auto find_next=[&]() {
                int l=i,r=n;
                while(l<r) {
                    int mid=(l+r+1)/2;
                    if(st.query(i, mid)<=cur) l=mid;
                    else r=mid-1;
                }
                return l;
            };

            int idx=find_next();
            if(idx==n) break;
            cur=st.query(i, idx+1);
        }
    }

    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    res.emplace_back(INF);

    for(int i=0;i<res.size();i++) {
        if(res[i]!=i+1) {
            printf("%d\n",i+1);
            return;
        }
    }
}

int main() {
    int t;
    io>>t;
    while(t--) solve();
    return 0;
}