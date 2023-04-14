#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,p,q,r,s;
    cin>>n>>p>>q>>r>>s;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=p;i<=q;i++) swap(arr[i],arr[i+r-p]);
    for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}