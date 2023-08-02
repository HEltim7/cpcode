#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    int sq=sqrt(n)+1;
    sq+=sq+10;

    for(int i=1;i<=n;i++) cin>>arr[i];

    int ans=n;
    auto cal=[&](int c) {
        int res=n;
        for(int i=1;i<=c;i++) {
            int cnt=0;
            for(int j=i;j<=n&&cnt<ans;j+=c)
                if(arr[j]!=k) cnt++;
            res=min(res,cnt);
        }
        return res;
    };

    for(int i=m;i<=min(n,m+sq);i++) {
        ans=min(ans,cal(i)+i-m);
    }
    for(int i=m;i>=max(1,m-sq);i--) {
        ans=min(ans,cal(i)+m-i);
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