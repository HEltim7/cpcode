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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> row(10);
    vector<int> col(10);
    vector<pair<int,int>> arr;
    for(int i=1;i<=m;i++) {
        int r,c;
        cin>>r>>c;
        row[r]++;
        col[c]++;
        arr.emplace_back(r,c);
    }
    for(auto [r,c]:arr) {
        if((row[r-1]==0&&r-1>=1)||(row[r+1]==0&&r+1<=n)||(col[c-1]==0&&c-1>=1)||(col[c+1]==0&&c+1<=n)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}