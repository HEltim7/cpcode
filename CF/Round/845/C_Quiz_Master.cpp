#include <vector>
#include <cassert>
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
int arr[N],cnt[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    int ans=N,zero=m;

    auto upd=[&](int x,int sign) {
        for(int i=1;i*i<=x;i++) {
            if(x%i==0) {
                auto fn=[&](int &cur) {
                    if(cur==0&&cur+sign==1) zero--;
                    else if(cur==1&&cur+sign==0) zero++;
                    cur+=sign;
                };

                if(i<=m) fn(cnt[i]);
                if(x/i<=m) fn(cnt[x/i]);
            }
        }
    };

    int l,r;
    for(l=1,r=0;l<=n&&r<=n;upd(arr[l++],-1)) {
        while(r+1<=n&&(r<l||zero)) upd(arr[++r],1);
        if(zero==0) ans=min(ans,arr[r]-arr[l]);
    }
    if(ans==N) cout<<-1<<endl;
    else cout<<ans<<endl;
    
    while(l<=n) upd(arr[l++],-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}