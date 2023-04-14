#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL a[N],b[N],c[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i],c[i]=1LL*a[i]*b[i];

    int ans=1;
    LL gc=c[1],lc=b[1];
    for(int i=2;i<=n;i++) {
        gc=gcd(gc,c[i]);
        lc=lcm(lc,b[i]);
        if(gc<lc||gc%lc) {
            ans++;
            gc=c[i];
            lc=b[i];
        }
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