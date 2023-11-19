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

#define endl '\n'
using LL=long long;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<vector<int>> adj(n+1);
    vector<int> p(n+1);
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++) cin>>p[i];

    constexpr int N=1e5,B=320,C=N/B+1;
    using Query=tuple<int,int,int,int>;
    vector<Query> query;
    vector<int> ans(q+1),id(q+1),ed(q+1);

    int idx=0;
    function<void(int,int)> dfs=[&](int u,int fa) {
        id[u]=++idx;
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs(v,u);
            }
        }
        ed[u]=idx;
    };
    dfs(1,0);

    for(int i=1;i<=q;i++) {
        int l,r,x;
        cin>>l>>r>>x;
        query.emplace_back(l,r,x,i);
    }


    auto mo=[&](){
        auto getid=[](int x) {
            return x/B;
        };

        vector<int> cnt(C+1);
        vector<bool> mark(n+1);
        vector<int> lbd,rbd;
        for(int l=1,r=B-1;l<=n;l=r+1,r+=B) {
            lbd.emplace_back(l);
            rbd.emplace_back(r);
        }
        rbd.back()=n;

        sort(query.begin(),query.end(),[&](const Query &x,const Query &y) {
            const auto &[l,r,_,__]=x;
            const auto &[L,R,___,____]=y;
            if(getid(l)!=getid(L)) return getid(l)<getid(L);
            return getid(l)&1?r<R:r>R;
        });

        int l=1,r=0,res=0;
        
        auto add=[&](int idx) {
            int x=id[p[idx]];
            mark[x]=1;
            cnt[getid(x)]++;
        };

        auto del=[&](int idx) {
            int x=id[p[idx]];
            mark[x]=0;
            cnt[getid(x)]--;
        };

        auto check=[&](int l,int r) {
            auto bf=[&](int l,int r) {
                for(int i=l;i<=r;i++) if(mark[i]) return true;
                return false;
            };
            int lid=getid(l),rid=getid(r);
            if(lid==rid) return bf(l,r);
            else {
                if(bf(l,rbd[lid])) return true;
                for(int i=lid+1;i<rid;i++) if(cnt[i]) return true;
                if(bf(lbd[rid],r)) return true;
                return false;
            }
        };
        
        for(const auto &[L,R,x,qid]:query) {
            while(l>L) add(--l);
            while(r<R) add(++r);
            while(l<L) del(l++);
            while(r>R) del(r--);
            ans[qid]=check(id[x],ed[x]);
        }
    };
    mo();

    for(int i=1;i<=q;i++) cout<<(ans[i]?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}