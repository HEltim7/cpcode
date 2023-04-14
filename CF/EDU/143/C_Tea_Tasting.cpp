#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL a[N],b[N],res[N],pre[N],cnt[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+b[i];
    for(int i=1;i<=n;i++) res[i]=0,cnt[i]=0;

    for(int i=1;i<=n;i++) {
        if(b[i]>=a[i]) {
            res[i]+=a[i];
        }
        else {
            int l=i,r=n;
            while(l<r) {
                int mid=l+r+1>>1;
                if(pre[mid]-pre[i-1]<=a[i]) l=mid;
                else r=mid-1;
            }
            res[r+1]+=a[i]-(pre[r]-pre[i-1]);
            cnt[i]++,cnt[r+1]--;
        }
    }
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=n;i++) {
        res[i]+=b[i]*cnt[i];
        cout<<res[i]<<" \n"[i==n];
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