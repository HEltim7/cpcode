#pragma GCC optimize("O2")
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

namespace mo {
    constexpr int N=1e4+10,Q=1e4+10,M=1e6+10,block=223;
    using Query=tuple<int,int,int,int>;
    vector<Query> query;
    int ans[Q],w[N],cnt[M],p[Q],nw[Q];
    
    void solve() {
        auto getid=[](int x) {
            return x/block;
        };

        sort(query.begin(),query.end(),[&](const Query &x,const Query &y) {
            const auto &[l,r,t,_]=x;
            const auto &[L,R,T,__]=y;
            if(getid(l)!=getid(L)) return getid(l)<getid(L);
            if(getid(r)!=getid(R)) return getid(r)<getid(R);
            return t<T;
        });

        int l=1,r=0,tm=0,res=0;
        
        auto add=[&](int idx) {
            if(++cnt[w[idx]]==1) res++;
        };

        auto del=[&](int idx) {
            if(--cnt[w[idx]]==0) res--;
        };

        auto modify=[&](int t) {
            if(p[t]>=l&&p[t]<=r) del(p[t]);
            swap(w[p[t]],nw[t]);
            if(p[t]>=l&&p[t]<=r) add(p[t]);
        };

        auto rollback=[&](int t) {
            modify(t);
        };
        
        for(const auto &[L,R,T,id]:query) {
            while(l>L) add(--l);
            while(r<R) add(++r);
            while(l<L) del(l++);
            while(r>R) del(r--);
            while(tm<T) modify(++tm);
            while(tm>T) rollback(tm--);
            ans[id]=res;
        }
    }
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>mo::w[i];
    int qid=0;
    for(int i=1,t=0;i<=q;i++) {
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='Q') mo::query.emplace_back(x,y,t,++qid);
        else {
            mo::p[++t]=x;
            mo::nw[t]=y;
        }
    }
    mo::solve();
    for(int i=1;i<=qid;i++) cout<<mo::ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}