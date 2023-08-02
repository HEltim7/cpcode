#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL arr[N];

void solve() {
    int n;
    LL p,x,q,y;
    cin>>n>>p>>x>>q>>y;
    
    LL sum=0;
    LL tot=0;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i],tot+=arr[i]/y;
    
    auto cal=[&](LL sum) {
        return (n-(sum%n))%n*p;
    };

    LL ans=cal(sum);
    for(int i=1;i<=min(LL(n),tot);i++) {
        LL cur=sum-i*y;
        ans=min(ans,i*q+cal(cur));
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}