#include <vector>
#include <cassert>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10,B=30;
vector<int> op[N][2];
int a[N],b[N],c[N];
PII qry[N];
LL ans[N];

struct DisjointUnionSet {
    vector<int> fa,sz;
    vector<pair<int&,int>> fah,szh;

    void init(int n) {
        fa.resize(n+1);
        sz.resize(n+1,1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        while(x!=fa[x]) x=fa[x];
        return x;
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    LL cal(int x) {
        return 1LL*sz[x]*(sz[x]-1)/2;
    }

    bool join(int x,int y,LL &ans) {
        x=find(x);
        y=find(y);
        if(x==y) {
            fah.emplace_back(fa[0],fa[0]);
            szh.emplace_back(sz[0],sz[0]);
            return false;
        }
        ans-=cal(x);
        ans-=cal(y);
        if(sz[x]<sz[y]) swap(x,y);
        fah.emplace_back(fa[y],fa[y]);
        szh.emplace_back(sz[x],sz[x]);
        sz[x]+=sz[y];
        fa[y]=x;
        ans+=cal(x);
        return true;
    }

    void undo(LL &ans) {
        assert(!fah.empty());
        int x=fah.back().first;
        int y=fah.back().second;
        ans-=cal(x);
        fah.back().first=fah.back().second;
        szh.back().first=szh.back().second;
        ans+=cal(x);
        ans+=cal(y);
        fah.pop_back(),szh.pop_back();
    }

    int size(int x) {
        return sz[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
} dsu(N);

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];

    int q;
    cin>>q;
    for(int i=1;i<=q;i++) {
        cin>>qry[i].first;
        qry[i].second=i;
    }
    sort(qry+1,qry+q+1);

    for(int i=B-1;i>=0;i--) {
        if(k>>i&1^1) continue;
        for(int j=1;j<=m;j++) {
            int d=c[j]^k;
            d^=1<<i;
            int mask=~((1<<i)-1);
            int t=mask;
            d&=mask;

            int l=lower_bound(qry+1,qry+q+1,PII(d,0))-qry;
            int r=upper_bound(qry+1,qry+q+1,PII(d|~mask,N))-qry;
            if(l<r) {
                op[l][1].emplace_back(j);
                op[r][0].emplace_back(j);
            }
        }
    }

    LL res=0;
    for(int i=1;i<=q;i++) {
        for(int j:op[i][0]) dsu.undo(res);
        for(int j:op[i][1]) dsu.join(a[j], b[j], res);
        ans[qry[i].second]=res;
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}