#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int r[N];

void solve() {
    int n,s1,s2;
    cin>>n>>s1>>s2;
    
    vector<pair<int,int>> arr;
    for(int i=1;i<=n;i++) cin>>r[i],arr.emplace_back(r[i],i);

    auto get=[](int x) {
        return 1LL*(x+1)*x/2;
    };
    int idx=0;
    LL sum=get(n)*s2;
    LL minn=sum;
    for(int i=1;i<=n;i++) {
        sum=get(i)*s1+get(n-i)*s2;
        if(sum<minn) {
            minn=sum;
            idx=i;
        }
    }

    vector<int> ans[2];
    vector<pair<LL,int>> cost;
    for(int i=1;i<=idx;i++) cost.emplace_back(1LL*s1*i,0);
    for(int i=1;i<=n-idx;i++) cost.emplace_back(1LL*s2*i,1);
    sort(cost.begin(),cost.end());

    sort(arr.begin(),arr.end(),greater<>());
    for(int i=0;i<n;i++) {
        auto [_,id]=cost[i];
        ans[id].push_back(arr[i].second);
    }
    cout<<ans[0].size()<<' ';
    for(int x:ans[0]) cout<<x<<' ';
    cout<<endl;
    cout<<ans[1].size()<<' ';
    for(int x:ans[1]) cout<<x<<' ';
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