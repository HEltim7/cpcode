#include <array>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
constexpr int N=1e6+10;
int pre[N],arr[N],ans[N];

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
Fenwick<> tr;

void solve() {
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cin>>m;
    vector<TIII> query;
    query.reserve(m);
    for(int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        query.emplace_back(r,l,i);
    }
    sort(query.begin(),query.end());

    int idx=0;
    tr.resize(N);
    for(auto [r,l,id]:query) {
        while(idx<r) {
            int x=arr[++idx];
            if(pre[x]) tr.add(pre[x], -1);
            tr.add(pre[x]=idx, 1);
        }
        ans[id]=tr.query(r)-tr.query(l-1);
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}