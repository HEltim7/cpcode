#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

int next_floor(int k,int i) {
    return k/(k/i);
}

int next_ceil(int k,int i) {
    if(k-1<i) return i;
    return (k-1)/((k-1)/i);
}

void solve() {
    int n;
    cin>>n;
    vector<int> arr(N),ans(N);
    vector<bool> mark(N);
    vector<vector<int>> pos(N);
    int mx=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        mx=max(mx,arr[i]);
        pos[arr[i]].emplace_back(i);
    }

    for(int i=N-1;i>=1;i--) {
        for(auto p:pos[i]) {
            if(mark[p]) continue;
            int l=p-1,r=p+1;
            while(l>=1&&!mark[l]&&arr[l]<=arr[l+1]) l--;
            while(r<=n&&!mark[r]&&arr[r]<=arr[r-1]) r++;
            l++,r--;
            for(int j=l;j<=r;j++) mark[j]=1;
            
            for(int j=1;;) {
                int res=(i+j-1)/j;
                ans[j]+=res;
                j=next_ceil(i, j)+1;
                if(j>i) break;
                ans[j]-=res;
            }
        }
    }

    debug(ans,1,mx);
    for(int i=1;i<=mx;i++) cout<<(ans[i]+=ans[i-1])<<" \n"[i==mx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}