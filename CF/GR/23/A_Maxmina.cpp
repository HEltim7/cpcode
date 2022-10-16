#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    bool one=0;
    for(int i=1;i<=n;i++) cin>>arr[i],one|=arr[i]&1;
    if(!one) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}