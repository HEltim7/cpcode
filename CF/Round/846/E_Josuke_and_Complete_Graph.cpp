#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL l,r;
    cin>>l>>r;
    LL ans=max(0LL,r/2-l+1);
    auto div=[](LL x,LL y) { return (x+y-1)/y; };

    for(LL i=1;i<l;) {
        LL j=div(l,div(l,i)-1)-1;
        LL g=r/(div(l,i)+1);
        ans+=max(0LL,min(j,g)-i+1);
        i=j+1;
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