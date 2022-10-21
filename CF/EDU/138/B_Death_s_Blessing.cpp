#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL a[N],b[N];

void solve() {
    int n;
    cin>>n;
    LL ans=0,maxx=0;
    for(int i=1;i<=n;i++) cin>>a[i],ans+=a[i];
    for(int i=1;i<=n;i++) cin>>b[i],ans+=b[i],maxx=max(maxx,b[i]);
    cout<<ans-maxx<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}