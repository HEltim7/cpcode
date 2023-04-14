#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL arr[N],pre[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],pre[i]=pre[i-1]+arr[i];
    int ans=0;
    map<LL,int> mp;
    int i=1;
    for(;arr[i]&&i<=n;i++) ans+=pre[i]==0;
    while(i<=n) {
        mp.clear();
        mp[pre[i]]=1;
        for(i++;i<=n&&arr[i];i++) mp[pre[i]]++;
        int maxx=0;
        for(auto [x,y]:mp) maxx=max(maxx,y);
        ans+=maxx;
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