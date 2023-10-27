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
    int n,m,k;
    cin>>n>>m>>k;
    vector<LL> arr(m+1);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr[in]++;
    }
    auto pre=arr;
    sort(pre.begin()+1,pre.end(),greater<>());
    partial_sum(pre.begin(),pre.end(),pre.begin());

    for(int i=1;i<=m;i++) {
        if(pre[m]-arr[i]<k) {
            cout<<-1<<" \n"[i==n];
            continue;
        }

        int l=1,r=m;
        while(l<r) {
            int m=(l+r+1)/2;
            LL cur=pre[m]-pre[m-1];
            LL sum=pre[m]-cur*m;
            if(arr[i]>=cur) sum-=arr[i]-cur;
            if(sum<=k) l=m;
            else r=m-1;
        }
        LL cur=pre[l]-pre[l-1];
        LL sum=pre[l]-cur*l;
        if(arr[i]>=cur) sum-=arr[i]-cur;
        LL lef=k-sum;
        LL t=l-(arr[i]>=cur);
        assert(t>0);
        LL ans=cur-lef/t;
        cout<<ans<<" \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}