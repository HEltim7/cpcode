#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e3;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid=vector<vector<int>>(n+1,vector<int>(m+1));
    vector<vector<int>> cnt=vector<vector<int>>(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            cin>>grid[i][j];

    auto check=[&](int x) {
        if(x>n||x>m) return false;
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=m;j++) 
                cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+(grid[i][j]>=x);
        for(int i=x;i<=n;i++)
            for(int j=x;j<=m;j++) {
                int p=i-x;
                int q=j-x;
                if(cnt[i][j]+cnt[p][q]-cnt[i][q]-cnt[p][j]==x*x) return true;
            }
        return false;
    };

    int l=1,r=N;
    while(l<r) {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}