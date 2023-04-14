#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL a,b;
    cin>>a>>b;

    LL ans=2e9;
    for(int i=1;i<=int(1e5);i++) {
        LL res=i-1;
        res+=(a+i-1)/i;
        res+=(b+i-1)/i;
        ans=min(ans,res);
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