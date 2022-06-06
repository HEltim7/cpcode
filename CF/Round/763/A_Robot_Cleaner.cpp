#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m,r,c,dr,dc;
    cin>>n>>m>>r>>c>>dr>>dc;
    int ans=1e6;
    ans=min(ans,abs(r-dr)+(r>dr?(n-r)*2:0));
    ans=min(ans,abs(c-dc)+(c>dc?(m-c)*2:0));
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