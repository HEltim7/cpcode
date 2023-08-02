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
    int n,d;
    cin>>n>>d;
    int ans=0;
    vector<string> s(n);
    for(auto &x:s) cin>>x;
    for(int i=1,pre=0;i<=d;i++) {
        bool cur=1;
        for(auto &x:s) cur&=x[i-1]=='o';
        if(cur) pre++;
        else pre=0;
        ans=max(ans,pre);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}