#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<pair<LL,LL>> arr(n);
    LL ans=0;
    for(auto &[y,x]:arr) {
        cin>>x>>y;
        ans+=x*2+y*2;
        if(x>y) swap(x,y);
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<arr.size();i++) {
        auto [y,x]=arr[i-1];
        ans-=y*2;
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