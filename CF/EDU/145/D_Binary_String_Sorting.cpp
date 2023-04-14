#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
constexpr LL coin=1e12,INF=1e18;
LL pre[N],suf[N];

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='1');
    suf[n+1]=0;
    for(int i=n;i>=1;i--) suf[i]=suf[i+1]+(s[i]=='0');

    LL ans=INF;
    for(int i=0;i<=n;i++) ans=min(ans,(pre[i]+suf[i+1])*(coin+1));
    for(int i=1;i<n;i++) {
        if(s[i]=='1'&&s[i+1]=='0') {
            ans=min(ans,(pre[i-1]+suf[i+2])*(coin+1)+coin);
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