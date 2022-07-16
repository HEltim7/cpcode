#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL arr[N];

void solve() {
    int n;
    LL ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],ans+=arr[i];
    int l=0;
    for(int i=1;i<=n;i++) if(arr[i]) {
        l=i;
        break;
    }
    int r=l;
    if(l==0) {
        cout<<0<<endl;
        return;
    }
    for(;;) {
        while(r<=n&&arr[r]) r++;
        if(r>n) break;
        arr[r]++,arr[l]--;
        ans++;
        while(arr[l]==0) l++;
    }
    cout<<ans-arr[n]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}