#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL arr[N];
LL pre[N];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    LL k,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    sort(arr+1,arr+1+n,greater<LL>());
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];

    if(sum<=k) {
        cout<<0<<endl;
        return;
    }
    debug(arr,1,n);
    LL ans=sum-k;
    LL minn=arr[n];
    for(int i=0;i<n;i++) {
        LL suf=pre[n-1]-pre[i];
        LL aim=k-suf;
        LL x;
        if(aim>=0) x=(aim)/(i+1);
        else x=(aim-i)/(i+1);
        x=min(minn,x);
        ans=min(ans,minn-x+i);
        debug(i,x,aim,i+1,ans);  
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}