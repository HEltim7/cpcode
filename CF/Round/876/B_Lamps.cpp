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

constexpr int N=2e5+10;

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(auto &[a,b]:arr) cin>>a>>b;
    sort(arr.begin(),arr.end(),[](pair<int,int> x, pair<int,int> y) {
        if(x.first!=y.first) return x.first<y.first;
        return x.second>y.second;
    });

    LL ans=0;
    map<int,int> mp;
    for(int cnt=0,i=0;i<arr.size();) {
        auto [a,b]=arr[i];
        cnt++;
        ans+=b;
        mp[a]++;
        if(cnt>=a) {
            while(cnt>=a&&i<arr.size()) {
                tie(a,b)=arr[++i];
            }
            mp.clear();
            cnt=0;
        }
        else i++;

        while(mp.size()&&cnt>=mp.begin()->first) {
            cnt-=mp.begin()->second;
            mp.erase(mp.begin());
        }
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