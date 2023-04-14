#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL pre[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i],pre[i]+=pre[i-1];
    LL ans=1;
    for(int i=1;i<n;i++) ans=max(ans,gcd(pre[i],pre[n]-pre[i]));
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