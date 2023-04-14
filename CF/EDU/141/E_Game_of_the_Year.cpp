#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int a[N],b[N],cnt[N];
bool mark[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cnt[i]=0,mark[i]=0;
    for(int i=1;i<=n;i++) if(a[i]>b[i]) cnt[b[i]]++,cnt[a[i]]--;
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int x=1;x<=n;x++) {
        for(int k=1;x*k<=n;k++) {
            if(cnt[x*k]) mark[k]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=!mark[i];
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) if(!mark[i]) cout<<i<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}