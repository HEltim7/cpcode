#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=-1e9;
    for(int i=0;i<n;i++) ans=max(ans,arr[i]-arr[(i+1)%n]);
    int maxx=-1e9,minn=1e9;
    for(int i=1;i<n;i++) maxx=max(maxx,arr[i]);
    for(int i=0;i<n-1;i++) minn=min(minn,arr[i]);
    ans=max(ans,maxx-arr[0]);
    ans=max(ans,arr[n-1]-minn);
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