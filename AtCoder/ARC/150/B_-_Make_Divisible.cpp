#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

LL add_a(LL a,LL b) {
    LL ans=1e18;
    for(int i=0;i<=a;i++) {
        LL A=a+i;
        LL k=(b+A-1)/A;
        ans=min(ans,i+(A*k-b));
    }
    return ans;
}

LL add_k(LL a,LL b) {
    int k=ceil(1.*b/a);
    LL ans=a*k-b;
    for(k--;k>=1;k--) {
        LL A=a+(b-a*k+k-1)/k;
        LL B=A*k;
        ans=min(ans,A-a+B-b);
    }
    return ans;
}

void solve() {
    LL a,b;
    cin>>a>>b;
    if(a>=b) cout<<a-b<<endl;
    else if(b%a==0) cout<<0<<endl;
    else {
        LL B=sqrt(b);
        if(a<=B) cout<<add_a(a, b)<<endl;
        else cout<<add_k(a, b)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}