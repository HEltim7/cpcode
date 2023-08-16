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
    int n,m,d;
    cin>>n>>m>>d;
    vector<int> arr(m+2);
    for(int i=1;i<=m;i++) cin>>arr[i];
    LL sum=m+(arr[1]!=1);
    arr[0]=1;
    arr[m+1]=n+1;
    auto cal=[&](int i,int j) {
        return (arr[i]-arr[j]-1)/d;
    };
    for(int i=1;i<=m+1;i++) {
        sum+=cal(i,i-1);
    }
    
    int minn=1e9,cnt=0;
    for(int i=1;i<=m;i++) {
        if(arr[i]==1) continue;
        int x=cal(i+1,i-1);
        int y=cal(i,i-1)+cal(i+1,i)+1;
        if(x-y<minn) {
            minn=x-y;
            cnt=1;
        }
        else if(x-y==minn) cnt++;
    }

    if(minn==0) cout<<sum<<' '<<m<<endl;
    else cout<<sum+minn<<' '<<cnt<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}