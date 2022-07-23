#pragma GCC optimize("Ofast")
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

struct Query {
    int op,a,b;
} query[N];

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

    template<typename T> void reads_impl(T& x) { rd(x); }
    template<typename T,typename... U> 
    void reads_impl(T& x,U&... y) { rd(x),reads_impl(y...); }

    #define read(x) io::rd(x)
    #define reads(...) io::reads_impl(__VA_ARGS__)
}

void solve() {
    int n=read(n),q=read(q);
    for(int i=0;i<n;i++) read(arr[i]);
    for(int i=0;i<q;i++) {
        read(query[i].op);
        if(query[i].op==1) reads(query[i].a,query[i].b);
        else read(query[i].a);
        query[i].a--,query[i].b--;
    }
    bitset<N> st;
    for(int i=q-1;i>=0;i--) {
        if(query[i].op==1) {
            int pos=query[i].b;
            int len=query[i].b-query[i].a+1;
            auto suf=st&~bitset<N>()>>(N-pos-1);
            auto pre=st&~bitset<N>()<<(pos+1);
            st=suf^pre>>len;
        }
        else st.flip(query[i].a);
    }
    int ans=0;
    for(int i=0;i<n;i++) if(st[i]) ans^=arr[i];
    printf("%d\n",ans);
}

int main() {
    int t=read(t);
    while(t--) solve();
    return 0;
}