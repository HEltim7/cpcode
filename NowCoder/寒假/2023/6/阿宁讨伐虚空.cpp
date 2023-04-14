#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;

void solve() {
    int n,l,r;
    cin>>n>>l>>r;
    cout<<fixed<<setprecision(15);
    if(l>=n) cout<<0;
    else if(r<n) cout<<1;
    else cout<<LD(n-1-l+1)/(r-l+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}