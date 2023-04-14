#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
bool mark[N];

void solve() {
    int n,k;
    cin>>n>>k;
    LL ans=0;

    for(int i=1+k+1;i<=n;i++) ans++,mark[i]=1;
    for(int i=2;i+k+1<=n;i++) {
        if(!mark[i]) {
            mark[i]=1;
            int res=i;
            for(int j=i+k+1;j<=n&&res>1;j++) res=min(res,gcd(i,j));
            ans+=res;
        }
    }
    for(int i=2;i<=n;i++) if(!mark[i]) ans+=i;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}