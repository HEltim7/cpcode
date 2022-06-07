#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'

void solve() {
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    vector<int> arr;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in>=l&&in<=r) arr.push_back(in);
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for(auto x:arr) 
        if(x<=k) k-=x,ans++;
        else break;
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