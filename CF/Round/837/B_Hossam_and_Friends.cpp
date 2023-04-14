#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int suf[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) suf[i]=n;
    while(m--) {
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        suf[x]=min(suf[x],y-1);
    }
    for(int i=n-1;i>=1;i--) suf[i]=min(suf[i],suf[i+1]);

    LL ans=0;
    for(int i=1;i<=n;i++) ans+=suf[i]-i+1;
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