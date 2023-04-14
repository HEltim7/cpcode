#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL a,b,n,m;
    cin>>a>>b>>n>>m;
    LL ans=min(n/(m+1)*m*a+(n-n/(m+1)*(m+1))*min(a,b),n*min(a,b));
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