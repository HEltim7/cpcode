#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL arr[N];

void solve() {
    int n;
    cin>>n;
    LL sum=0,ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i],arr[i]=abs(arr[i]),sum+=arr[i];
    ans=sum*2*n;
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