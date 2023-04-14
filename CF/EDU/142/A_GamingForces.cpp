#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    int ans=0,cnt=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]==1) cnt++;
        else ans++;
    }
    ans+=cnt/2+cnt%2;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}