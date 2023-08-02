#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    int a=0,b=0;
    int n;
    cin>>n;
    for(int i=1,in;i<=n;i++) {
        cin>>in;
        if(in==1) a++;
        else b++;
    }

    int ans=max(0,(n+1)/2-a);
    a+=ans,b-=ans;
    if(b&1) ans++;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}