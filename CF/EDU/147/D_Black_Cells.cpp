#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,INF=2e9;
int l[N],r[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>l[i];
    for(int i=1;i<=n;i++) cin>>r[i];

    int ans=INF;
    for(int i=1,len=0,one=0;i<=n;i++) {
        int cur=r[i]-l[i]+1;
        len+=cur;
        if(cur==1) one++;
        if(len>=k) {
            int off=len-k;
            int t=min(off,one);
            int res=r[i]-(off-t);
            res+=(i-t)*2;
            ans=min(ans,res);
        }
    }
    if(ans==INF) ans=-1;
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