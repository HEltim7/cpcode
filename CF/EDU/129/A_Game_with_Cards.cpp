#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m,a=-1,b=-1,in;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in,a=max(a,in);
    cin>>m;
    for(int i=1;i<=m;i++) cin>>in,b=max(b,in);
    if(a>=b) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
    if(b>=a) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}