#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n,d,k;
    cin>>n>>d>>k;
    LL lc=lcm(n,d);
    LL round=d*(k-1)/lc;
    LL pos=d*(k-1)%n;
    cout<<pos+round<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}