#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],maxx[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i]=i-arr[i]+1;
        maxx[i]=max(maxx[i-1],arr[i]);
    }
    LL ans=0;
    for(int i=1,r=1;i<=n;i++) {
        while(r<n&&maxx[r+1]<=i) r++;
        ans+=r-i+1;
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