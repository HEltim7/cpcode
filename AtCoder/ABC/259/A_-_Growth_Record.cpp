#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m,x,t,d;
    cin>>n>>m>>x>>t>>d;
    if(m>=x) cout<<t;
    else cout<<t-(x-m)*d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}