#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n;
    cin>>n;
    if(n&1) cout<<-1<<endl;
    else cout<<n/2<<' '<<0<<' '<<0<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}