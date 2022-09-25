#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10,INF=0x3f3f3f3f;
PII arr[N];
int pre[N],suf[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first;
    for(int i=1;i<=n;i++) cin>>arr[i].second;
    sort(arr+1,arr+1+n);
    pre[0]=suf[n+1]=0;
    for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],arr[i].second);
    for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],arr[i].second);
    int maxx=pre[n],pos=0;
    for(int i=1;i<=n;i++)
        if(arr[i].second==maxx) {
            pos=arr[i].first;
            break;
        }

    debug(maxx);
    for(int i=1;i<=n;i++) 
        if(pre[i]!=maxx||suf[i]!=maxx) {
            if(pre[i]==maxx) arr[i].first=max(pos,arr[i].first-(maxx-arr[i].second));
            else arr[i].first=min(pos,arr[i].first+(maxx-arr[i].second));
        }
    sort(arr+1,arr+1+n);
    debug(arr,1,n);
    double res=(double(1)*arr[n].first+arr[1].first)/2;
    cout<<fixed<<setprecision(7)<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}