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

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> num(n+1),dp(n+1);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        num[in]=i;
    }

    int len=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        in=num[in];
        
        int l=0,r=len;
        while(l<r) {
            int mid=(l+r+1)/2;
            if(dp[mid]<in) l=mid;
            else r=mid-1;
        }
        dp[l+1]=in;
        if(l==len) len++;
    }
    cout<<len<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}