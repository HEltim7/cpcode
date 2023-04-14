#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL h[N],v[N];

void solve() {
    int n,t,a;
    cin>>n>>t>>a;
    for(int i=1;i<=n;i++) cin>>h[i]>>v[i],v[i]=a-v[i]*t;
    LL ans=1-t;
    for(int i=1;i<=n;i++) {
        if(h[i]<=a) ans+=t;
        else {
            if(v[i]<=0) {
                cout<<"-1";
                return;
            }

            ans+=t,h[i]-=a;
            ans+=(h[i]+v[i]-1)/v[i]*t;
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}