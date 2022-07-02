#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int a[N],b[N];

void solve() {
    int n,x;
    cin>>n>>x;
    LL ans=3e18,pre=0;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=min(n,x);i++) {
        pre+=a[i]+b[i];
        int t=x-i;
        ans=min(ans,pre+1LL*t*b[i]);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}