#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    LL ans=0;
    LL pre[2]{};
    for(int i=1;i<=n;i++) {
        if(arr[i]==0) continue;
        bool idx=arr[i]>0;
        if(pre[idx]<abs(arr[i])) {
            ans+=abs(arr[i])-pre[idx];
            pre[idx]+=abs(arr[i])-pre[idx];
        }
        pre[idx^1]+=abs(arr[i]);
        pre[idx]-=abs(arr[i]);
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