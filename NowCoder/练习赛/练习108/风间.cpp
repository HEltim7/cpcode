#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL a[N],b[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    LL ans=0;
    for(int i=1;i<n;i++) {
        if(abs(a[i]-b[i])&1) {
            ans=-1;
            break;
        }
        LL dif=a[i]-b[i];
        a[i]-=dif;
        a[i+1]+=dif;
        ans+=abs(dif)/2;
    }
    if(a[n]!=b[n]) ans=-1;
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