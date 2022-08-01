#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
LL arr[N],bak[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

void solve() {
    int n,m;
    while(cin>>n>>m) {
        for(int i=1;i<=n;i++) cin>>arr[i];
        int ans=0;
        for(int k=1;k<=60;k++) {
            for(int i=1;i<=n;i++) bak[i]=arr[i]+k*i;
            sort(bak+1,bak+1+n);
            LL sum=0;
            for(int i=1;i<=k;i++) sum+=bak[i];
            if(sum<=m) ans=k;
            else break;
        }
        cout<<ans;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}