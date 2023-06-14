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

constexpr int N=2e3+10;
int l[N],r[N],dp[N*2];

void solve() {
    int n;
    cin>>n;
    vector<int> num;
    for(int i=1;i<=n;i++) {
        cin>>l[i]>>r[i];
        num.push_back(l[i]);
        num.push_back(r[i]);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) {
        l[i]=lower_bound(num.begin(),num.end(),l[i])-num.begin()+1;
        r[i]=lower_bound(num.begin(),num.end(),r[i])-num.begin()+1;
    }
    for(int i=0;i<=num.size();i++) dp[i]=0;

    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) {
        int a=l[i],b=r[i];
        for(int j=i+1;j<=n;j++) {
            int x=l[j],y=r[j];
            if(min(b,y)>=max(a,x)) {
                v.emplace_back(max(b,y),min(a,x));
            }
        }
    }
    sort(v.begin(),v.end());

    int ans=0;
    int idx=0;
    for(auto [R,L]:v) {
        while(idx<L) {
            dp[idx+1]=max(dp[idx+1],dp[idx]);
            idx++;
        }
        dp[R]=max(dp[R],dp[L-1]+2);
        ans=max(ans,dp[R]);
    }

    cout<<n-ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}