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
constexpr int N=5e5+10;
int arr[N],tmp[N],pre[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i],tmp[i]=arr[i];
    if(n==1) {
        if(m>=arr[1]) cout<<1<<endl;
        else cout<<2<<endl;
        return;
    }
    sort(tmp+1,tmp+1+n);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+tmp[i];
    int res=upper_bound(pre+1,pre+1+n,m)-pre-1;
    if(res>=n) {
        cout<<1<<endl;
        return;
    }
    else if(res==0) {
        cout<<n+1<<endl;
        return;
    }
    debug(res);
    
    m-=arr[res+1];
    for(int i=1;i<=n;i++) 
        if(tmp[i]==arr[res+1]) {
            swap(tmp[i],tmp[n]);
            break;
        }
    sort(tmp+1,tmp+n);
    for(int i=1;i<res;i++) m-=tmp[i];
    if(m>=0) cout<<n-res<<endl;
    else cout<<n-res+1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}