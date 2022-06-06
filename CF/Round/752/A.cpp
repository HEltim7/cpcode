#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,in,maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in,maxx=max(maxx,in-i);
    cout<<maxx<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}