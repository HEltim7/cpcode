#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int p[N],arr[N],pos[N];

void solve() {
    int n,m,d;
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++) cin>>p[i],pos[p[i]]=i;
    for(int i=1;i<=m;i++) cin>>arr[i];

    int ans=N;
    for(int i=1;i<m;i++) {
        if(pos[arr[i]]<pos[arr[i+1]]&&pos[arr[i+1]]<=pos[arr[i]]+d) {
            if(d<n-1) ans=min(ans,d+1-(pos[arr[i+1]]-pos[arr[i]]));
            ans=min(ans,pos[arr[i+1]]-pos[arr[i]]);
        }
        else {
            cout<<0<<endl;
            return;
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