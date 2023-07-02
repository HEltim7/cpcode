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
    int n;
    cin>>n;
    vector<tuple<int,LL,LL>> arr;
    for(int i=1;i<=n;i++) {
        LL a,b;
        cin>>a>>b;
        arr.emplace_back(i,a,b);
    }

    sort(arr.begin(),arr.end(),[](auto x,auto y) {
        auto [idx,ax,bx]=x;
        auto [idy,ay,by]=y;
        if(ax*(ay+by)!=ay*(ax+bx)) return ax*(ay+by)>ay*(ax+bx);
        return idx<idy;
    });

    for(auto [a,b,c]:arr) cout<<a<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}