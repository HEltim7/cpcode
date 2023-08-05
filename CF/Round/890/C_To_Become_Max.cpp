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
    int n,k;
    cin>>n>>k;
    vector<LL> arr(n+1);
    LL maxx=0;
    for(int i=1;i<=n;i++) cin>>arr[i],maxx=max(maxx,arr[i]);

    auto check=[&](LL mid) {
        for(int z=1;z<n;z++) {
            LL t=k-(mid-arr[z]);
            LL cur=mid;
            for(int i=z+1;i<=n&&t>=0;i++) {
                if(arr[i]>=cur-1) return true;
                t-=max(0LL,cur-1-arr[i]);
                cur=max(cur-1,arr[i]);
            }
        }
        return false;
    };

    int l=0,r=n;
    while(l<r) {
        int mid=(l+r+1)/2;
        if(check(maxx+mid)) l=mid;
        else r=mid-1;
    }

    cout<<maxx+l<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}