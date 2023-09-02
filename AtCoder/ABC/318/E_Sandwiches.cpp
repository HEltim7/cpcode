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
    vector<int> arr(n+1);
    auto pos=vector(int(3e5+10),vector<int>());
    for(int i=1;i<=n;i++) cin>>arr[i],pos[arr[i]].emplace_back(i);

    LL ans=0;
    for(int i=1;i<pos.size();i++) {
        if(pos[i].empty()) continue;
        for(int j=0;j+1<pos[i].size();j++) {
            int l=j+1;
            int r=pos[i].size()-l;
            ans+=1LL*(pos[i][j+1]-pos[i][j]-1)*l*r;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}