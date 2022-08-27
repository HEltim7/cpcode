#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=20;
LL cnt[N],H;
int n=10;

void solve() {
    cin>>H;
    LL ans=0;
    for(int i=1;i<=n;i++) cin>>cnt[i];
    for(int i=n;i>=1;i--) {
        LL dif=H-ans;
        ans+=min(dif/i,cnt[i])*i;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}