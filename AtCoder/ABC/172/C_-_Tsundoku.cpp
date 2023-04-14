#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL pre1[N],pre2[N];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1,in;i<=n;i++) cin>>in,pre1[i]=pre1[i-1]+in;
    for(int i=1,in;i<=m;i++) cin>>in,pre2[i]=pre2[i-1]+in;

    int ans=0;
    for(int i=0;i<=n&&pre1[i]<=k;i++) {
        int l=0,r=m;
        while(l<r) {
            int mid=l+r+1>>1;
            if(pre2[mid]+pre1[i]>k) r=mid-1;
            else l=mid;
        }
        ans=max(ans,i+l);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}