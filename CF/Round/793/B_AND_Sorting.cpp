#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=1;i<=n;i++) {
        int in ;
        cin>>in;
        arr.push_back(in);
    }
    vector<int> bak(arr);
    int ans=-1;
    sort(bak.begin(),bak.end());
    for(int i=0;i<n;i++) if(arr[i]!=bak[i]) {
        if(ans==-1) ans=arr[i];
        else ans&=arr[i];
    }
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