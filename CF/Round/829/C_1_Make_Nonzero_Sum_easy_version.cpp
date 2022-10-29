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
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(n&1) {
        cout<<"-1"<<endl;
        return;
    }

    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i+=2) {
        if(arr[i]==arr[i+1]) ans.emplace_back(i,i+1);
        else ans.emplace_back(i,i),ans.emplace_back(i+1,i+1);
    }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}