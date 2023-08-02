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
constexpr int N=2e5+10;
int tmp[N],arr[N];
int mp[N],l[N],r[N];

template<typename T=int,T init=T()> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        assert(pos>0);
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=init;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    void resize(int n) {
        size=n;
        tr.resize(size+1,init);
    }

    Fenwick()=default;
    Fenwick(int n):size(n) { tr.resize(size+1,init); }
};
Fenwick<> tr(N);

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    int tot=0;
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        tmp[i]=in=='1';
        tot+=tmp[i];
    }

    set<int> st;
    for(int i=1;i<=n;i++) st.insert(i);

    int idx=0;
    for(int i=1;i<=m;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=m&&st.size();i++) {
        auto it=st.lower_bound(l[i]);
        while(it!=st.end()) {
            int val=*it;
            if(val>r[i]) break;
            else {
                mp[val]=++idx;
                arr[idx]=tmp[val];
                if(arr[idx]) tr.add(idx, 1);
                it=st.erase(it);
            }
        }
    }
    debug(mp,1,n);
    debug(tot);

    while(q--) {
        int p;
        cin>>p;
        if(mp[p]) {
            p=mp[p];
            tot-=arr[p];
            tr.add(p, -arr[p]);
            
            arr[p]=1-arr[p];
            tot+=arr[p];
            tr.add(p, arr[p]);
        }
        else {
            tot-=tmp[p];
            tmp[p]=1-tmp[p];
            tot+=tmp[p];
        }

        int t=min(tot,idx);
        int ans=t-tr.query(t);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}