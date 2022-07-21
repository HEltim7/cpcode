#pragma GCC optimize("Ofast")
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

namespace io {
    const int MAXBUF = 1e6;
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

template<typename T> 
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
    int n=read(n),q=read(q);
    Fenwick<int> fen(n+10);
    for(int i=1;i<=n;i++) read(arr[i]);
    int ans=0;
    for(int i=1;i<=q;i++) {
        int op=read(op);
        if(op==1) {
            int l=read(l),r=read(r);
            fen.add(r+1, r-l+1);
        }
        else {
            int pos=read(pos);
            pos-=fen.query(pos);
            assert(pos>=0);
            ans^=arr[pos];
        }
    }
    printf("%d\n",ans);
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}