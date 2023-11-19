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
    vector<int> arr(n);
    for(int &x:arr) cin>>x;

    LL ans=0;
    for(int i=2,cur=arr.back();i<=n;i++) {
        int x=arr.end()[-i];
        if(x>cur) {
            int t=(x+cur-1)/cur;
            ans+=t-1;
            cur=x/t;
        }
        else cur=x;
    }
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