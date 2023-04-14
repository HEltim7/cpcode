#pragma GCC optimize("O2")
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

namespace mo {
    constexpr int N=5e4+10,Q=2e5+10,M=1e6+10,block=112;
    using Query=tuple<int,int,int>;
    vector<Query> query;
    int ans[Q],w[M],cnt[M];
    
    void solve() {
        auto getid=[](int x) {
            return x/block;
        };

        sort(query.begin(),query.end(),[&](const Query &x,const Query &y) {
            const auto &[l,r,_]=x;
            const auto &[L,R,__]=y;
            if(getid(l)!=getid(L)) return getid(l)<getid(L);
            return getid(l)&1?r<R:r>R;
        });

        int l=1,r=0,res=0;
        
        auto add=[&](int idx) {
            if(++cnt[w[idx]]==1) res++;
        };

        auto del=[&](int idx) {
            if(--cnt[w[idx]]==0) res--;
        };
        
        for(const auto &[L,R,id]:query) {
            while(l>L) add(--l);
            while(r<R) add(++r);
            while(l<L) del(l++);
            while(r>R) del(r--);
            ans[id]=res;
        }
    }

    void clear() { query.clear(); }
}

void solve() {
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>mo::w[i];
    cin>>q;
    for(int i=1;i<=q;i++) {
        int l,r;
        cin>>l>>r;
        mo::query.emplace_back(l,r,i);
    }
    mo::solve();
    for(int i=1;i<=q;i++) cout<<mo::ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}