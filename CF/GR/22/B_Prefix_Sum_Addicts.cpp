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
LL pre[N],arr[N];

void solve() {
    int n,k,t;
    cin>>n>>k;
    t=n-k+1;
    for(int i=t;i<=n;i++) cin>>pre[i];
    if(k==1) {
        cout<<"Yes"<<endl;
        return;
    }
    for(int i=t+1;i<=n;i++) {
        arr[i]=pre[i]-pre[i-1];
        if(i>t+1&&arr[i]<arr[i-1]) {
            cout<<"No"<<endl;
            return;
        }
    }
    LL last=arr[t+1];
    LL sum=t*last;
    debug(last,t,pre[t],sum);
    if(sum>=pre[t]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}