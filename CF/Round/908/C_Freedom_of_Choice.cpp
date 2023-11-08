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
    int m;
    cin>>m;
    vector<int> n(m);
    vector<LL> l(m),r(m),tot(m),num;
    vector<vector<pair<LL,LL>>> st(m);

    LL L=0,R=0;
    for(int i=0;i<m;i++) {
        cin>>n[i]>>l[i]>>r[i];
        L+=l[i],R+=r[i];
        st[i].resize(n[i]);
        for(int j=0;j<n[i];j++) cin>>st[i][j].first,num.emplace_back(st[i][j].first);
        for(int j=0;j<n[i];j++) cin>>st[i][j].second,tot[i]+=st[i][j].second;
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    
    if(R-L+1>num.size()) {
        cout<<0<<endl;
        return;
    }
    for(LL i=L;i<=R;i++) num.emplace_back(i);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    
    auto get=[&](LL x) {
        return lower_bound(num.begin(),num.end(),x)-num.begin();
    };

    vector<vector<pair<int,LL>>> vec(num.size());
    for(int i=0;i<m;i++) {
        for(auto [x,y]:st[i]) vec[get(x)].emplace_back(i,y);
    }

    LL ans=1e18;
    for(int i=get(L);i<=get(R);i++) {
        auto &v=vec[i];
        LL res=0,sum=R;
        for(auto [x,y]:v) {
            LL lef=tot[x]-y;
            LL take=min(lef,r[x]);
            LL add=max(l[x]-take,0LL);
            res+=add;
            sum=sum-r[x]+take+add;
        }

        res+=max(num[i]-sum,0LL);
        ans=min(ans,res);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}