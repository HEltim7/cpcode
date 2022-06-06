#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n,k;
    cin>>n>>k;
    LL ans=0,maxx=0;
    vector<LL> arr[2];
    for(int i=1;i<=n;i++) {
        LL in;
        cin>>in;
        if(in==0) continue;
        if(in>0) arr[1].push_back(in);
        else arr[0].push_back(-in);
        maxx=max(maxx,abs(in));
    }
    for(int z=0;z<=1;z++) {
        if(arr[z].empty()) continue;
        sort(arr[z].begin(),arr[z].end());
        for(int i=arr[z].size()-1;i>=0;i-=k) {
            ans+=2*arr[z][i];
        }
    }
    cout<<ans-maxx<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}