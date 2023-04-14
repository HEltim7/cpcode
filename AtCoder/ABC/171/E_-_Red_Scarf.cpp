#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],xr[N],ans[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) xr[i]=arr[i]^arr[i%n+1];
    ans[1]=arr[2];
    for(int i=3;i<=n;i+=2) ans[1]^=xr[i];
    for(int i=1;i<=n;i++) ans[i%n+1]=ans[i]^xr[i];
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}