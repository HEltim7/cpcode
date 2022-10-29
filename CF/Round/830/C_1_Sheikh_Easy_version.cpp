#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL arr[N],pre[N],prx[N];

pair<int,int> check(int n,int len,LL val) {
    for(int i=len;i<=n;i++) {
        if(pre[i]-pre[i-len]-(prx[i]^prx[i-len])==val)
            return {i-len+1,i};
    }
    return {-1,-1};
}

void solve() {
    int n,L,R,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        pre[i]=pre[i-1]+arr[i];
        prx[i]=prx[i-1]^arr[i];
    }
    cin>>L>>R;
    LL val=pre[n]-prx[n];
    debug(val);
    
    int l=1,r=n;
    int ll=1,rr=n;
    while(l<r) {
        int mid=l+r>>1;
        auto res=check(n, mid, val);
        if(res.first!=-1) {
            ll=res.first;
            rr=res.second;
            r=mid;
        }
        else l=mid+1;
    }
    cout<<ll<<' '<<rr<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}