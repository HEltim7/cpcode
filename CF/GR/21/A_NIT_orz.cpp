#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    LL z,ans=0;
    cin>>n>>z;
    for(int i=1;i<=n;i++) {
        LL in;
        cin>>in;
        ans=max(ans,in|z);
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