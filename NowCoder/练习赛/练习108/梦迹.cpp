#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
int arr[N];

template<typename T=int> struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) {
        aim+=val;
    }

    void add(int pos,T val) {
        pos++;
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        pos++;
        if(pos<=0) return 0;
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};
Fenwick<> tr(N);

void solve() {
    int n,q,w;
    cin>>n>>q>>w;
    LL ans=0;

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        tr.add(arr[i], 1);
    }
    for(int i=1;i<=n;i++) {
        ans+=tr.query(w-arr[i]);
        if(arr[i]+arr[i]<=w) ans++;
    }
    for(int i=1;i<=q;i++) {
        int p,x;
        cin>>p>>x;
        ans-=tr.query(w-arr[p])*2;

        tr.add(arr[p], -1);
        arr[p]=x;
        tr.add(arr[p], 1);
        ans+=tr.query(w-arr[p])*2;

        debug(ans);
        cout<<ans/2<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}