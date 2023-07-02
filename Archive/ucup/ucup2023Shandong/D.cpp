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

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;

template<typename T=int,T init=T()> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
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

void solve() {
    int n,q;
    cin>>n>>q;
    Fenwick<int> cnt(n);
    Fenwick<LL> arr(n);
    multimap<LL,int> mp;

    for(int i=1;i<=n;i++) {
        LL in;
        cin>>in;
        mp.emplace(in,i);
        arr.add(i, in);
    }

    while(q--) {
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}