#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,len=1e9;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i],len=min(len,arr[i]);

    LL maxx=len*2-1;
    LL res=0;
    for(auto x:arr) res+=(x+maxx-1)/maxx-1;
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}