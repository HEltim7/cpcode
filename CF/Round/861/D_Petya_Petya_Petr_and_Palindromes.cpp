#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],lf[N],rt[N],cnt[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int i=k,j=1;i>=1;i--,j++) lf[i]=min(j,i);
    for(int i=k,j=1;i<=n;i++,j++) lf[i]=j;
    for(int i=n,j=n-k+1;i>=1;i--,j++) rt[i]=min(i,j);

    LL ans=0;
    auto work=[&](int idx) {
        int l=idx,r=idx-2,tot=0;

        auto add=[&](int idx) {
            if(idx>=1&&idx<=n) {
                cnt[arr[idx]]++;
                tot++;
            }
        };

        auto del=[&](int idx) {
            if(idx>=1&&idx<=n) {
                cnt[arr[idx]]--;
                tot--;
            }
        };
        
        for(int i=idx;i<=n;i+=2) {
            while(l>lf[i]) l-=2,add(l);
            while(r<rt[i]) r+=2,add(r);
            while(l<lf[i]) del(l),l+=2;
            while(r>rt[i]) del(r),r-=2;
            ans+=tot-cnt[arr[i]];
        }
        memset(cnt, 0, sizeof cnt);
    };

    work(1),work(2);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}