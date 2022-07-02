#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    LL sum=0,in;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in,sum+=in;
    if(sum%n) cout<<1<<endl;
    else cout<<0<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}