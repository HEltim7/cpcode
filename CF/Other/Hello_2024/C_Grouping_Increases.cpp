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
    int ans=0;
    int s=1e9,t=1e9;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        bool x=s>=in;
        bool y=t>=in;
        if(x&&y) {
            if(s>=t) t=in;
            else s=in;
        }
        else if(x) s=in;
        else if(y) t=in;
        else {
            ans++;
            if(s<=t) s=in;
            else t=in;
        }
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