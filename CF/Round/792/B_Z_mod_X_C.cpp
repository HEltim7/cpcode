#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL a,b,c;
    cin>>a>>b>>c;
    LL x=a;
    LL k=(c-a)/b+1;
    x+=k*b;
    assert(x>c);
    cout<<x<<' '<<b<<' '<<c<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}