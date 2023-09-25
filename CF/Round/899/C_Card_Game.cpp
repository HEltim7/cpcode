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
    int n;
    cin>>n;
    vector<LL> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    LL sum=0,mx=0,ans=0;
    for(int i=n;i>=1;i--) {
        if(i&1) {
            if(arr[i]>=0) {
                ans+=sum+arr[i];
                sum=0;
                mx=0;
            }
            else mx=max(mx,sum+arr[i]);
        }
        else {
            if(arr[i]<=0) {
                ans+=sum;
                sum=0;
                mx=0;
            }
            else {
                mx=max(mx,sum);
                sum+=arr[i];
            }
        }
    }

    ans+=mx;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}