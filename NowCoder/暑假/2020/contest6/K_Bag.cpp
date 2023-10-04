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

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    io>>n>>k;
    vector<int> arr(n+2),num;
    for(int i=1;i<=n;i++) num.emplace_back(read(arr[i]));
    if(*max_element(arr.begin()+1,arr.begin()+n+1)>k) {
        printf("NO\n");
        return;
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        arr[i]=lower_bound(num.begin(),num.end(),arr[i])-num.begin()+1;

    auto init=[&]() {
        vector<bool> pre(n+2);
        vector<int> cnt(n+2);
        for(int l=0,r=1,dif=0;r<=n;r++) {
            if(++cnt[arr[r]]==1) dif++;
            if(r-l>k) if(--cnt[arr[++l]]==0) dif--;
            if(dif==r-l) pre[r]=r-k>=1?pre[r-k]:true;
        }
        return pre;
    };
    
    auto &&pre=init();
    reverse(arr.begin(),arr.end());
    auto &&suf=init();
    reverse(suf.begin(),suf.end());

    for(int i=1;i<=n;i++) {
        if(pre[i]&&(i==n||suf[i+1])) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    io>>t;
    while(t--) solve();
    return 0;
}