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
    LL x,y;
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);

    LL ans=0;
    int idx=0;
    while(idx<n&&arr[idx+1]<=x+idx) idx++;

    if(x+idx>=y) cout<<y-x<<endl;
    else if(n-idx>=idx) cout<<-1<<endl;
    else {
        for(;x<y&&idx<n&&idx<y-x;) {
            LL len=min(y-x-idx,arr[idx+1]-(x+idx));
            LL step=idx-(n-idx);
            LL round=(len+step-1)/step;
            ans+=round*n;
            x+=round*step;
            while(idx<n&&arr[idx+1]<=x+idx) idx++;
        }
        ans+=y-x;
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}