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

namespace fast_io {
    constexpr int MAXBUF = 1<<20;
    char buf[MAXBUF];

    char gc() {
        static char *pl=nullptr,*pr=nullptr;
        return (pl==pr&&(
            pr=(pl=buf)+fread(buf,1,MAXBUF,stdin),pl==pr
        )?EOF:*pl++);
    }

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

    struct IO {
        template<typename T> friend IO&
        operator>>(IO &io, T& x) { rd(x); return io; }
    } static io;
}
using fast_io::io;

struct CartesianTree {
    vector<int> lch,rch;
    int root;

    void build(const vector<int> &v) {
        int n=v.size(),top=0;
        vector<int> stk(n+1);
        lch.resize(n+1);
        rch.resize(n+1);

        for(int i=1;i<=n;i++) {
            int k=top;
            while(k&&v[stk[k]-1]>v[i-1]) k--;
            if(k) rch[stk[k]]=i;
            else root=i;
            if(k<top) lch[i]=stk[k+1];
            stk[++k]=i;
            top=k;
        }
    }
};

void solve() {
    int n;
    io>>n;
    vector<int> p(n);
    for(int &x:p) io>>x;
    CartesianTree tr;
    tr.build(p);
    LL l=0,r=0;
    for(int i=1;i<=n;i++) {
        l^=1LL*i*(tr.lch[i]+1);
        r^=1LL*i*(tr.rch[i]+1);
    }
    printf("%lld %lld",l,r);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    solve();
    return 0;
}