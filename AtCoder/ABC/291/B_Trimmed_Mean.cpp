#include <vector>
#include <iomanip>
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
using LD=long double;

void solve() {
    int n;
    cin>>n;
    LL sum=0,cnt=3*n;
    vector<int> arr(n*5);
    for(auto &x:arr) cin>>x;
    sort(arr.begin(),arr.end());
    for(int i=n,j=1;j<=cnt;i++,j++) sum+=arr[i];
    debug(sum,cnt);
    LD res=LD(sum)/cnt;
    cout<<fixed<<setprecision(15);
    cout<<res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}