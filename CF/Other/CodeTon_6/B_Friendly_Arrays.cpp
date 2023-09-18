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
    int n,m;
    cin>>n>>m;
    int a=0,b=0;
    for(int i=1,in;i<=n;i++) cin>>in,a^=in;
    for(int i=1,in;i<=m;i++) cin>>in,b|=in;
    if(n&1) cout<<a<<' '<<(a|b)<<endl;
    else cout<<(a&(~b))<<' '<<a<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}