#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n,k,d,w;
    cin>>n>>k>>d>>w;
    for(int i=1;i<=n;i++) cin>>arr[i];

    int ans=0;
    for(int i=1;i<=n;) {
        int j=i;
        int t=arr[i]+w+d;
        while(j<=n&&j-i+1<=k&&arr[j]<=t) j++;
        i=j;
        ans++;
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