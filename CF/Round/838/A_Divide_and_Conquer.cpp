#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,ans=1e9,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        sum+=in;
        int odd=in&1;
        for(int j=1;in;j++) {
            in/=2;
            if((in&1)!=odd) {
                ans=min(ans,j);
                break;
            }
        }
    }
    if(sum&1) cout<<ans<<endl;
    else cout<<0<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}