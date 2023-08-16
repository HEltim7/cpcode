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

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    s=" "+s;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) arr[i]=s[i]-'0';

    auto cnt=vector(2,vector(n+1,0));
    for(int i=1;i<=n;i++) cnt[arr[i]][i]++;
    partial_sum(cnt[0].begin(),cnt[0].end(),cnt[0].begin());
    partial_sum(cnt[1].begin(),cnt[1].end(),cnt[1].begin());

    auto pre=vector(2,vector(n+2,vector(n+1,0)));
    auto suf=vector(2,vector(n+2,vector(n+1,0)));
    
    for(int z=0;z<=1;z++) {
        for(int i=1;i<=n;i++) {
            int cnt=0;
            for(int j=i;j>=1;j--) {
                if(arr[j]!=z) cnt++;
                pre[z][i][cnt]=i-j+1;
            }
            for(int j=0;j<=k;j++)
                pre[z][i][j]=max({
                    pre[z][i][j],
                    pre[z][i-1][j],
                    j?pre[z][i][j-1]:0
                });
        }
        for(int i=n;i>=1;i--) {
            int cnt=0;
            for(int j=i;j<=n;j++) {
                if(arr[j]!=z) cnt++;
                suf[z][i][cnt]=j-i+1;
            }
            for(int j=0;j<=k;j++)
                suf[z][i][j]=max({
                    suf[z][i][j],
                    suf[z][i+1][j],
                    j?suf[z][i][j-1]:0
                });
        }
    }

    auto mx=vector(n+1,-1);
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            int zero=pre[0][i][j];
            int one=suf[1][i+1][k-j];
            mx[zero]=max(mx[zero],one);

            zero=suf[0][i+1][j];
            one=pre[1][i][k-j];
            mx[zero]=max(mx[zero],one);
        }
    }

    for(int i=1;i<=n;i++) {
        LL ans=0;
        for(int j=0;j<=n;j++) {
            if(mx[j]!=-1) {
                ans=max(ans,1LL*i*j+mx[j]);
            }
        }
        cout<<ans<<" \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}