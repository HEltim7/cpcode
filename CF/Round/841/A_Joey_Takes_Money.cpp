#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    LL ans=1;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        ans*=in;
    }
    cout<<(ans+n-1)*2022<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}