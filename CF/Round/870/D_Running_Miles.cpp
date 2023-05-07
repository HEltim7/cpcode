#include <algorithm>
#include <array>
#include <cassert>
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
constexpr int N=1e5+10;
int arr[N],f[N][3];

void solve() {
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        f[i][0]=max(f[i-1][0],arr[i]+i);
        f[i][1]=max(f[i-1][1],arr[i]+f[i-1][0]);
        f[i][2]=max(f[i-1][2],arr[i]+f[i-1][1]);
        ans=max(ans,f[i][2]-i);
    }
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