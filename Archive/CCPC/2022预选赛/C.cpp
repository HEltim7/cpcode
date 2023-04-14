#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
#define endl '\n'

void solve() {
    LL a,b,cnta=0,cntb=0;
    cin>>a>>b;
    while(a&&a%2==0) a/=2,cnta++;
    while(b&&b%2==0) b/=2,cntb++;
    cout<<(cnta/2+1)<<' '<<(cnta>cntb?0:1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}