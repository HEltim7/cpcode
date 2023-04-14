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
constexpr int N=1e3+10;
bool grid[N][N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>grid[i][j];
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int r=n-i+1;
            int c=n-j+1;
            debug(i,j,r,c);
            if(grid[i][j]!=grid[r][c]) cnt++;
        }
    }
    cnt/=2;

    if(k<cnt) cout<<"NO"<<endl;
    else {
        int left=k-cnt;
        if(n&1) cout<<"YES"<<endl;
        else {
            if(left%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}