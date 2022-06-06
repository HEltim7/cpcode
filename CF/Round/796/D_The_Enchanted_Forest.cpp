#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL arr[N],pre[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n,k;
    LL ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i],pre[i]=arr[i]+pre[i-1];
    if(k>=n) {
        ans+=pre[n];
        debug(ans);
        LL end=1LL*(n+1)*n/2;
        ans+=1LL*n*k-end;
        cout<<ans<<endl;
    }
    else{
        for(int i=1,j=i+k-1;j<=n;i++,j++) {
            ans=max(ans,pre[j]-pre[i-1]);
        }
        ans+=1LL*k*(k-1)/2;
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}