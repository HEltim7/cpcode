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

#define endl '\n'
using LL=long long;

void solve() {
    int n,p;
    cin>>n>>p;
    vector<pair<int,int>> arr(n);
    for(auto &[a,b]:arr) cin>>b;
    for(auto &[a,b]:arr) cin>>a;
    sort(arr.begin(),arr.end());

    LL sum=p;
    int cnt=n-1;
    for(auto [a,b]:arr) {
        if(a>=p) break;
        int t=min(b,cnt);
        cnt-=t;
        sum+=1LL*t*a;
        if(cnt==0) break;
    }
    sum+=1LL*p*cnt;
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}