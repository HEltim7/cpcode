#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    vector<int> arr(4);
    for(int i=0;i<4;i++) cin>>arr[i];
    int ans=arr[0];
    if(ans) ans+=min(arr[1],arr[2])*2;
    ans+=min((max(arr[1],arr[2])-min(arr[1],arr[2])+arr[3]),arr[0]+1);
    cout<<max(ans,1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}