#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(n==1) {
        if(arr[1]==1) cout<<0<<endl;
        else cout<<1<<endl;
    }
    else {
        int res=arr[1];
        for(int i=2;i<=n;i++) res=gcd(res,arr[i]);
        if(res==1) cout<<0<<endl;
        else {
            if(gcd(res,n)==1) cout<<1<<endl;
            else if(gcd(res,n-1)==1) cout<<2<<endl;
            else cout<<3<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}