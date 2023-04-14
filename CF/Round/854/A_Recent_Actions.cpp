#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;
bool mark[N];
int ans[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n+m;i++) mark[i]=0,ans[i]=-1;

    int dn=n;
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        if(!mark[in]&&dn) {
            mark[in]=1;
            ans[dn]=i;
            dn--;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}