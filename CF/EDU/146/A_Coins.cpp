#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL k,n;
    cin>>n>>k;
    if(n%2==0) cout<<"YES"<<endl;
    else {
        if(k<=n&&k%2==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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