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
constexpr int N=2e5+10;
int arr[N];
LL sum[N];
vector<int> pos[N];

template<typename T=int> struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) {
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
Fenwick<LL> tr(N),cnt(N);

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],pos[arr[i]].push_back(i);

    LL ans=0;
    for(LL len=1;len<=n;len++) ans+=(n-len+1)*(len/2);
    debug(ans);
    for(int i=1;i<=n;i++) {
        debug(i,pos[i]);
        for(int idx:pos[i]) {
            LL R=n-idx+1;
            LL L=R;
            LL rcnt=idx-1>=L+1?cnt.query(idx-1)-cnt.query(L):0;
            LL lval=tr.query(L);
            LL res=rcnt*R+lval;
            ans-=res;
            debug(idx,L,rcnt,lval,res);
            tr.add(idx, idx);
            cnt.add(idx, 1);
        }
        for(int idx:pos[i]) tr.add(idx, -idx),cnt.add(idx, -1);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}