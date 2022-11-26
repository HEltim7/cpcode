#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=double;
constexpr int N=1e6+10;
using PDL=pair<LD,LL>;
PDL g[N];
LL pre[N],suf[N];

LD solve(int n) {
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+g[i].second;
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+g[i].second;
    
    LD ans=0;
    for(int i=1;i<=n;i++) {
        LD px=1/g[i].first;
        LD pre_sum=pre[i]*px;

        auto cal=[&](int mid) {
            if(mid==n+1) return LD(0);
            LD py=1/(1-g[mid].first);
            LD suf_sum=suf[mid]*py;
            return suf_sum;
        };

        int l=i+1,r=n+1;
        while(l<r) {
            int mid=l+r>>1;
            if(cal(mid)>pre_sum) l=mid+1;
            else r=mid;
        }

        ans=max(ans,pre[i]+suf[l]-pre_sum);
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<PDL> bak;
    for(int i=1;i<=n;i++) cin>>g[i].first>>g[i].second;
    sort(g+1,g+1+n,greater<>());
    for(int i=1;i<=n;i++) {
        if(bak.size()&&g[i].first==bak.back().first)
            bak.back().second+=g[i].second;
        else bak.emplace_back(g[i].first,g[i].second);
    }
    n=bak.size();
    for(int i=1;i<=n;i++) g[i]={bak[i-1].first,bak[i-1].second};

    LD ans=solve(n);
    for(int i=1;i<=n;i++) g[i].first=1-g[i].first;
    reverse(g+1,g+1+n);
    ans=max(ans,solve(n));
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}