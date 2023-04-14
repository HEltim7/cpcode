#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL l,r,b,k;
    cin>>l>>r>>b>>k;
    
    cout<<k*((l+b-1)/b*b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}