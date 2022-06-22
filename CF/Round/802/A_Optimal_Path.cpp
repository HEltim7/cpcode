#include<array>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n,m;
    cin>>n>>m;
    LL sum=(1+m)*m/2-m+(1+n)*n/2*m;
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}