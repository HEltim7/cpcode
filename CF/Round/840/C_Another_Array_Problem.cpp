#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL arr[N];

void solve() {
    int n;
    cin>>n;
    LL ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i],ans+=arr[i];
    if(n==2) {
        ans=max(ans,abs(arr[1]-arr[2])*2);
    }
    else if(n==3) {
        ans=max({
            ans,
            arr[1]*3,
            arr[3]*3,
            abs(arr[2]-arr[1])*3,
            abs(arr[2]-arr[3])*3,
            abs(arr[2]-arr[1])+arr[3],
            abs(arr[2]-arr[3])+arr[1]
        });
    }
    else {
        LL maxx=arr[1];
        for(int i=1;i<=n;i++) maxx=max(maxx,arr[i]);
        ans=maxx*n;
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