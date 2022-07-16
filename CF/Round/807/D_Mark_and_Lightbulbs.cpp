#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[2][N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> seg[2];
    for(int i=0;i<2;i++) {
        for(int j=1;j<=n;j++) {
            char in;
            cin>>in;
            arr[i][j]=in-'0';
            if(arr[i][j-1]==0&&arr[i][j]) seg[i].emplace_back(j,-1);
            if(seg[i].size()&&seg[i].back().second==-1) {
                if(j==n&&arr[i][j]==1) seg[i].back().second=j;
                else if(arr[i][j]==0) seg[i].back().second=j-1;
            }
        }
    }
    bool ans=1;
    ans=min(ans,arr[0][1]==arr[1][1]);
    ans=min(ans,arr[0][n]==arr[1][n]);
    ans=min(ans,seg[0].size()==seg[1].size());
    if(!ans) cout<<-1<<endl;
    else {
        LL res=0;
        int len=seg[0].size();
        for(int i=0;i<len;i++) {
            res+=abs(seg[0][i].first-seg[1][i].first);
            res+=abs(seg[0][i].second-seg[1][i].second);
        }
        cout<<res<<endl;
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