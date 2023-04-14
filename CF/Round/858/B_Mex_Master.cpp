#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    int zero=0,one=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]==0) zero++;
        if(arr[i]==1) one++;
    }

    if(zero==n) cout<<1<<endl;
    else if(zero>((n+1)/2)) {
        if(one+zero==n) cout<<2<<endl;
        else cout<<1<<endl;
    }
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