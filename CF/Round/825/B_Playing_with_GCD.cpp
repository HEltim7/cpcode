#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int b[N],a[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    b[1]=a[1];
    b[n+1]=a[n];
    for(int i=2;i<=n;i++) b[i]=lcm(a[i-1],a[i]);
    for(int i=1;i<=n;i++) {
        if(gcd(b[i],b[i+1])!=a[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}