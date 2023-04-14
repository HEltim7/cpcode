#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,M=450;
int arr[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    arr[n+1]=n;
    int ans=0;
    for(int k=0;k<=min(m,M);k++) {
        for(int i=0,j=i+k;j<=n;i++,j++) {
            int len=arr[j+1]-arr[i];
            ans=max(ans,len-k*k);
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}