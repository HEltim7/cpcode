#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10;
int a[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[n]==1) {
        cout<<"NO"<<endl;
        return;
    }

    vector<int> ans;
    for(int i=n,cnt=0,rev=0;i>=1;i--) {
        if((a[i]^rev)==0) continue;
        ans.push_back(i);
        rev^=1;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n-ans.size();i++) cout<<0<<' ';
    while(ans.size()) {
        cout<<ans.back()<<' ';
        ans.pop_back();
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}