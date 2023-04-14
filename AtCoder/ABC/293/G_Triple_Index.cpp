#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
constexpr int N=2e5+10,len=500;
int arr[N],cnt[N];
LL ans[N];

void solve() {
    int n,q;
    cin>>n>>q;
    vector<TIII> Q(q);
    for(int i=1;i<=n;i++) cin>>arr[i];
    int qid=0;
    for(auto &[l,r,id]:Q) cin>>l>>r,id=++qid;

    auto getid=[&](int x) {
        return x/len;
    };

    sort(Q.begin(),Q.end(),[&](TIII &x,TIII &y) {
        auto [l,r,_]=x;
        auto [L,R,__]=y;
        if(getid(l)!=getid(L)) return getid(l)<getid(L);
        return r<R;
    });

    auto cal=[](LL x) {
        return x*(x-1)*(x-2)/2/3;
    };

    LL res=0;
    auto add=[&](int idx) {
        res-=cal(cnt[arr[idx]]);
        res+=cal(++cnt[arr[idx]]);
    };

    auto del=[&](int idx) {
        res-=cal(cnt[arr[idx]]);
        res+=cal(--cnt[arr[idx]]);
    };

    for(int i=0,l=1,r=0;i<q;i++) {
        auto [L,R,id]=Q[i];
        while(l<L) del(l++);
        while(l>L) add(--l);
        while(r<R) add(++r);
        while(r>R) del(r--);
        ans[id]=res;
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}