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
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    int ans=abs(arr[1]-arr[n]);
    for(int i=1,j=n;i<j;i++,j--) {
        int cur=abs(arr[i]-arr[j]);
        ans=gcd(ans,cur);
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