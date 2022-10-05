#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e2+10;
LL arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> tmp[k];
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        tmp[i%k].push_back(arr[i]);
    }
    for(int i=0;i<k;i++) sort(tmp[i].begin(),tmp[i].end());
    LL ans=0;
    for(int i=0;i<k;i++) ans+=tmp[i].back();
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