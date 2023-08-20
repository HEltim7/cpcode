#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
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
    int n;
    cin>>n;
    LL ans=numeric_limits<LL>().max();
    vector<int> arr(n);
    for(int &x:arr) cin>>x;
    int x,y;
    cin>>x>>y;
    x--,y--;

    LL res=0;
    for(int i=x;i!=y;i=(i+1)%n) res+=arr[i];
    ans=min(ans,res);
    res=0;
    for(int i=y;i!=x;i=(i+1)%n) res+=arr[i];
    ans=min(ans,res);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}