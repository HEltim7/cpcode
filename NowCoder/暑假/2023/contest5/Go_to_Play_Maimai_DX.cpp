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
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1),cnt(5);
    for(int i=1;i<=n;i++) cin>>arr[i];

    int ans=n;
    for(int i=1,j=0;i<=n;i++) {
        auto check=[&]() {
            return cnt[1]&&cnt[2]&&cnt[3]&&cnt[4]>=k;
        };
        while(j<n&&!check()) {
            cnt[arr[++j]]++;
        }
        if(!check()) break;
        ans=min(ans,j-i+1);
        cnt[arr[i]]--;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}