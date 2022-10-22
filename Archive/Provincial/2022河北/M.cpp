#include <vector>
#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;
using LL=long long;

void solve() {
    LL ans=0,pre=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) {
        LL in;
        cin>>in;
        ans+=in*pre;
        pre+=in;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}